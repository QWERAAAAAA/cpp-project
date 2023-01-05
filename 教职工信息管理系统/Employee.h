#include <iostream>
#include <string>
using namespace std;

/********************************************************
    头文件Employee.h
    内容：Employee、Faculty、Staff类
********************************************************/

// 声明全局函数
extern void addData(int);
extern void deleteData();
extern void search();
extern void show(int);
extern void Statistics(int);

// Employee基类
class Employee
{
protected:
    int type;          // 职工类别(1表示教师，2表示管理者)
    string id;         // 职工编号
    string name;       // 姓名
    string sex;        // 性别
    int birth;         // 出生年份
    string department; // 部门
    int workDay;       // 参加工作的年份
    int age;           // 年龄
    int workTime;      // 工龄

public:
    // 构造函数与析构函数
    Employee(int t, string i, string n, string s, int b, string d, int w)
    {
        type = t;
        id = i;
        name = n;
        sex = s;
        birth = b;
        department = d;
        workDay = w;
        time_t now = time(0); // 系统头文件<ctime>中的类和函数
        tm *ltm = localtime(&now);
        age = (1900 + ltm->tm_year) - b;
        workTime = (1900 + ltm->tm_year) - w;
    }
    Employee(){};
    virtual ~Employee(){}; // 涉及指针的虚函数的动态联编会出现delete指针的警告，设置为虚析构函数好的解决方法

    friend void addData(int);
    friend void deleteData();
    friend void search();
    friend void show(int);
    friend void Statistics(int);
    virtual void display() = 0;

    int getAge() // 加上getAge(),getWorkTime()函数，否则Employee为虚基类，无法完成后续的指针类型转换
    {
        return age;
    }
    int getWorkTime()
    {
        return workTime;
    }
};

// Faculty类
class Faculty : public Employee
{
    string title; // 职称
public:
    // 构造函数与析构函数
    Faculty(int t, string i, string n, string s, int b, string d, int w, string ti)
    {
        type = t;
        id = i;
        name = n;
        sex = s;
        birth = b;
        department = d;
        workDay = w;
        title = ti;
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        age = (1900 + ltm->tm_year) - birth;
        workTime = (1900 + ltm->tm_year) - workDay;
    }
    Faculty(){};
    ~Faculty() {}

    // 声明友元函数
    friend void addData(int);
    friend void deleteData();
    friend void search();
    friend void show(int);
    friend void Statistics(int);

    // 重载输入输出运算符
    friend ostream &operator<<(ostream &os, const Faculty &s)
    {
        os << s.type << " " << s.id << " " << s.name << " " << s.sex << " " << s.birth << " " << s.department
           << " " << s.workDay << " " << s.title;
        return os;
    }
    friend istream &operator>>(istream &is, Faculty &s)
    {
        is >> s.type >> s.id >> s.name >> s.sex >> s.birth >> s.department >> s.workDay >> s.title;
        return is;
    }

    // 实现虚函数
    virtual void display()
    {
        cout << " " << type << " " << id << " " << name << " " << sex << " " << birth << " " << department
             << " " << workDay << " " << title << " " << age << " " << workTime << endl;
    }
};

// Staff类
class Staff : public Employee
{
    string level; // 级别
public:
    // 构造函数与析构函数
    Staff(int t, string i, string n, string s, int b, string d, int w, string l)
    {
        type = t;
        id = i;
        name = n;
        sex = s;
        birth = b;
        department = d;
        workDay = w;
        level = l;
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        age = (1900 + ltm->tm_year) - birth;
        workTime = (ltm->tm_year + 1900) - workDay;
    }
    Staff(){};
    ~Staff(){};

    // 声明友元函数
    friend void addData(int);
    friend void deleteData();
    friend void search();
    friend void show(int);
    friend void Statistics(int);

    // 重载输入输出运算符
    friend ostream &operator<<(ostream &os, const Staff &s)
    {
        os << s.type << " " << s.id << " " << s.name << " " << s.sex << " " << s.birth << " " << s.department
           << " " << s.workDay << " " << s.level;
        return os;
    }
    friend istream &operator>>(istream &is, Staff &s)
    {
        is >> s.type >> s.id >> s.name >> s.sex >> s.birth >> s.department >> s.workDay >> s.level;
        return is;
    }

    // 实现虚函数
    virtual void display()
    {
        cout << " " << type << " " << id << " " << name << " " << sex << " " << birth << " " << department
             << " " << workDay << " " << level << " " << age << " " << workTime << endl;
    }
};
