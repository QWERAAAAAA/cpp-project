#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#define M 101
using namespace std;

/********************************************************
FileName:		学生信息管理系统
Author:        	M12J10
Created:       	2022/11/26
Description:	C++文本I/O
********************************************************/

// 定义学生结构体
struct Student{
    string name;
    string id;
    float score;
    int age;
};

// 定义变量
Student studs[M];
int countS = 0;
string fileName;
fstream iofile;

void OpenFile(){
    cout << " 请输入要打开的文件名(例如:1班.txt)    ";
    cin >> fileName;
    iofile.open(fileName, ios::out);
    if(!iofile){
        cout << "无法打开当前文件" << endl;
        exit(1);
    }
}

void AddStudent(){
    if(!iofile){
        cout << "未打开任何文件,操作失败" << endl;
        exit(1);
    }
    cout << "请输入学生信息, 输入顺序为学生姓名、学号、年龄、平均成绩" << endl;
    cout << "以‘#’表示输入结束" << endl;
    cin >> studs[countS].name;
    string c = studs[countS].name;
    while (c[0] != '#'){
        cin >> studs[countS].id >> studs[countS].age >> studs[countS].score;
        countS++;
        cin >> studs[countS].name;
        c = studs[countS].name;
    }
    for(int i = 0; i < countS; i++)
        iofile << studs[i].name << " " << studs[i].id << " " << studs[i].age << " " << studs[i].score << endl;
    cout << "添加完成" << endl;
}

void DeleteStudent(int s, string d){
    iofile.open(fileName, ios::trunc|ios::out);
    if(!iofile){
        cout << "未打开任何文件,操作失败" << endl;
        exit(1);
    }
    for(int i = 0; i < countS; i++){
        if((s == 1 && studs[i].id == d) || (s == 2 && studs[i].name == d)){
            for(int j = i; j < countS-1; j++){
                studs[j].id = studs[j+1].id;
                studs[j].age = studs[j+1].age;
                studs[j].name = studs[j+1].name;
                studs[j].score = studs[j+1].score;
            }
        }
        cout << "删除成功"  << endl;
        countS--;
        for(int i = 0; i < countS; i++){
            iofile << studs[i].name << " " << studs[i].id << " " << studs[i].age << " " << studs[i].score << endl;
        }
    }
}
void Show(){
    cout << "所有学生信息显示如下: " << endl;
    for(int i = 0; i < countS; i++){
        cout << i+1 << " " << "name: " << studs[i].name << " id: " << studs[i].id << " age: " << studs[i].age << " score: " << studs[i].score << endl;
    }
    cout << "学生总数为: " << countS << endl;
}
void NewFile(){
    string newFileName;
    cout << "请输入文件名: ";
    cin >> newFileName;
    iofile.open(newFileName, ios::out);
    if(!iofile){
        cout << "无法新建文件" << endl;
        exit(1);
    }
    for(int i = 0; i < countS; i++){
        iofile << studs[i].name << " " << studs[i].id << " " << studs[i].age << " " << studs[i].score << endl;
    }
    iofile.close();
    cout << "文件另存为成功" << endl;
}

void Menu(){
    	cout<<"|---------------学生信息管理系统---------|"<<endl;
		cout<<"|                1. 打开文件             |"<<endl;
		cout<<"|                2. 添加信息             |"<<endl;
		cout<<"|                3. 删除信息             |"<<endl;
		cout<<"|                4. 显示所有信息         |"<<endl;
		cout<<"|                5. 保存文件             |"<<endl;
		cout<<"|                6. 文件另存为           |"<<endl;
		cout<<"|                7. 退出系统             |"<<endl;
}

int main(){
    int num;
    string number, na;
    Menu();
    while(true){
        cout << "请输入操作序号：";
        cin >> num;
        switch (num)
        {
        case 1:     // 打开文件
            OpenFile();
            break;
        case 2:     // 添加信息
            AddStudent();
            break;
        case 3:     // 删除信息
            Show();
            cout << "请选择输入学生信息: 1. 学号     2. 姓名" << endl;
            int sw;
            cin >> sw;
            iofile.close();     // 先关闭文件，再以trunc方式打开文件，打开文件流时清空所有内容
            if(sw == 1){
                cout << "请输入学生学号:\t" ;
                cin >> number;
                DeleteStudent(sw, number);
            }
            if(sw == 2){
                cout << "请输入学生姓名:\t";
                cin >> na;
                DeleteStudent(sw, na);
            }
            break;
        case 4:     // 显示所有学生信息
            Show();
            break;
        case 5:     // 保存文件
            iofile.close();
            cout << "文件保存成功" << endl;
            break;
        case 6:     // 文件另存为
            NewFile();
            break;
        case 7:     // 退出系统
            if(iofile){
                cout << "当前文件未保存, 请保存" << endl;
                break;
            }
            else
                exit(1);
        default:
            break;
        }
    }
}
