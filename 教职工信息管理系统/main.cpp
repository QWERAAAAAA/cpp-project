#include <iostream>
#include "method.h"
using namespace std;

/********************************************************
    主函数main.cpp
    内容：菜单、全局变量
********************************************************/

// 定义全局变量
vector<Employee *> emp;
vector<Employee *> getTxt();
fstream iofile;
string txtName = "/Users/m12j10/Code/CPPFinalProject/employee.txt";

void menu()
{
    cout << "+---------------------------------------------+\n";
    cout << "|               教职工信息管理系统            |\n";
    cout << "+---------------------------------------------+\n";
    cout << "|            1、添加教职工信息                |\n";
    cout << "|            2、删除教职工信息                |\n";
    cout << "|            3、按姓名搜索教职工              |\n";
    cout << "|            4、浏览所有教职工信息            |\n";
    cout << "|            5、统计教职工平均年龄和工龄      |\n";
    cout << "+---------------------------------------------+\n";
    cout << "|                 0、退出                     |\n";
    cout << "+---------------------------------------------+\n";
}

int main()
{
    while (1)
    {
        menu();
        int choice;
        cout << "请输入操作序号: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "0 退出系统" << endl;
            exit(1);
            break;

        // 添加【按职工类型添加】
        case 1:
            int select0;
            cout << "请选择:1、添加教师信息, 2、添加管理员信息, 0、返回  \n";
            cin >> select0;
            if (select0 == 0)
                ;
            else
            {
                cout << "输入格式: 【职工类别 职工编号 姓名 性别 出生日期 部门 参加工作时间 职称或级别】\n";
                addData(select0);
            }
            break;

        // 删除【输入编号，打印删除信息，再次确认是否删除】
        case 2:
            int select;
            cout << "请选择:1、按编号删除, 0、返回  \n";
            cin >> select;
            if (select == 1)
                deleteData();
            else if (select == 0)
                ;
            else
                cout << " 选择错误。\n";
            break;

        // 搜索【按姓名搜索】
        case 3:
            int select1;
            cout << "请选择:1、按姓名搜索, 0、返回  \n";
            cin >> select1;
            if (select1 == 1)
                search();
            else if (select1 == 0)
                ;
            else
                cout << " 选择错误。\n";
            break;

        // 查看【可选择查看教师/管理员信息，打印显示为：基本信息加上年龄和工龄】
        case 4:
            int select2;
            cout << "请选择:1、查看所有教师信息, 2、查看所有管理员信息, 0、返回  \n";
            cin >> select2;
            if (select2 == 0)
                ;
            else
            {
                cout << "【职工类别 职工编号 姓名 性别 出生日期 部门 参加工作时间 职称或级别 年龄 工龄】\n";
                show(select2);
            }
            break;

        // 统计【可分别统计教师/管理员的平均年龄和工龄】
        case 5:
            int select3;
            cout << "请选择:1、统计教师的平均年龄和工龄, 2、统计管理员的平均年龄和工龄, 0、返回  \n";
            cin >> select3;
            if (select3 == 0)
                ;
            else
            {
                cout << "【平均年龄 平均工龄】\n";
                Statistics(select3);
            }
            break;
        default:
            printf("无此选项,请重新输入！\n");
        }
    }
    return 0;
}