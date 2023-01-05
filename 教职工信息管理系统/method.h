#include "Employee.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

/********************************************************
    头文件method.h
    内容：方法的实现
********************************************************/

// 声明全局变量
extern vector<Employee *> emp;
extern vector<Employee *> getTxt();
extern fstream iofile;
extern string txtName;

// 将txt文件内容读入数组
vector<Employee *> getTxt()
{
    vector<Employee *> tmp; // 定义临时的vector数组tmp，用于数据传递
    ifstream fp(txtName);
    if (!fp.is_open())
    {
        printf("出错了");
        exit(-1);
    }
    string text;
    while (!fp.eof())
    {
        getline(fp, text);
        vector<string> v; // 通过临时的vector数组v，将每一行数据内容的元素存入
        istringstream in(text);
        string temp;
        while (in >> temp)
        {
            v.push_back(temp);
        }
        if (text.length()) // 将数据对应转换为Faculty类型或Staff类型
        {
            if (v[0] == "1")
            {
                int type = stoi(v[0]);
                int bir = stoi(v[4]);
                int work = stoi(v[6]);
                tmp.push_back(new Faculty(type, v[1], v[2], v[3], bir, v[5], work, v[7]));
            }
            else
            {
                int type = stoi(v[0]);
                int bir = stoi(v[4]);
                int work = stoi(v[6]);
                tmp.push_back(new Staff(type, v[1], v[2], v[3], bir, v[5], work, v[7]));
            }
        }
    }
    fp.close();
    return tmp; // 将tmp的内容传递给emp
}

// 添加信息
void addData(int s)
{
    emp = getTxt(); // 将文本中的内容存入vector数组emp
    Faculty newFac;
    Staff newSta;
    if (s == 1)
        cin >> newFac;
    else
        cin >> newSta;
    for (int i = 0; i < emp.size(); i++)
    {
        if (emp[i]->id == newFac.id || emp[i]->id == newSta.id)
        {
            cout << "该职工编号已存在!不能重复添加." << endl;
            return;
        }
    }
    iofile.open(txtName, ios::out); // 打开文本文件，同时清空文本的所有内容
    if (s == 1)
    {
        emp.push_back(new Faculty(newFac.type, newFac.id, newFac.name, newFac.sex, newFac.birth, newFac.department, newFac.workDay, newFac.title));
    }
    else
    {
        emp.push_back(new Staff(newSta.type, newSta.id, newSta.name, newSta.sex, newSta.birth, newSta.department, newSta.workDay, newSta.level));
    }
    for (int i = 0; i < emp.size(); i++) // 重新将数组emp内容写入文本
    {
        if (emp[i]->type == 1) // 必须区分类型存入，因为基类无法获取到派生类的特有数据，无法写入职称和级别
        {
            Faculty *temp = (Faculty *)emp[i]; // 将Employee*指针类型强制转换为Faculty*指针类型
            iofile << *temp << endl;
        }
        else
        {
            Staff *temp = (Staff *)emp[i]; // 将Staff*指针类型强制转换为Staff*指针类型
            iofile << *temp << endl;
        }
    }
    iofile.close();
    cout << "添加完成" << endl;
}

// 删除信息
void deleteData()
{
    emp = getTxt();
    string id;
    bool flag; // 用于标记是否确认删除
    cout << "请输入要删除的职工编号: \n";
    cin >> id;
    for (int i = 0; i < emp.size(); i++)
    {
        if (emp[i]->id == id)
        {
            // 为了保证删除无误，先打印该职工信息
            cout << "职工信息:";
            emp[i]->display(); // 无需判断Faculty类还是Staff类，直接调用，因为display()是虚函数
            cout << "确认删除?(1.确认 2.取消)\n";
            int t;
            cin >> t;
            if (t == 1)
            {
                delete emp[i]; // erase不能彻底销毁指针，需要delete！
                emp.erase(emp.begin() + i);
                flag = true;
                break;
            }
            else
                return;
        }
    }
    if (flag) // 确认删除
    {
        iofile.open(txtName, ios::out);
        for (int i = 0; i < emp.size(); i++)
        {
            if (emp[i]->type == 1) // 同样的需要区分类型，再写入文件
            {
                Faculty *temp = (Faculty *)emp[i];
                iofile << *temp << endl;
            }
            else
            {
                Staff *temp = (Staff *)emp[i];
                iofile << *temp << endl;
            }
        }
        cout << "删除成功" << endl;
        iofile.close(); // 要记得关闭文件，否则无法保存修改
    }
    else
        cout << "未找到该职工编号, 删除失败\n";
}

// 按姓名搜索
void search()
{
    emp = getTxt();
    string name;
    bool flag = false;
    cout << "请输入要查找的职工姓名: \n";
    cin >> name;
    for (int i = 0; i < emp.size(); i++)
    {
        if (emp[i]->name == name)
        {
            emp[i]->display();
            flag = true;
        }
    }
    if (flag == false)
        cout << "未查找到该职工\n";
}

// 查看所有教职工信息
void show(int sel) // 传入需要浏览的职工类型
{
    emp = getTxt();
    for (int i = 0; i < emp.size(); i++)
    {
        if (emp[i]->type == sel) // 筛选
        {
            emp[i]->display(); // 调用虚函数display()
        }
    }
}

// 统计平均年龄和工龄
void Statistics(int ty) // 传入需要统计数据的职工类型
{
    emp = getTxt();
    int totalAge = 0;      // 统计总年龄
    int totalWorkTime = 0; // 统计总工龄
    int goal = 0;          // 统计人数
    for (int i = 0; i < emp.size(); i++)
    {
        if (emp[i]->type == ty) // 对职工类型进行筛选
        {
            totalAge += emp[i]->age;
            totalWorkTime += emp[i]->workTime;
            goal++;
        }
    }
    cout << "   " << (double)totalAge / goal << "     " << (double)totalWorkTime / goal << endl;
}