/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 21:10:15
 * @LastEditTime: 2024-10-22 22:26:34
 */



#include "Manager.h"
#include "ComputerRoom.h"
#include <iostream>
using namespace std;


// 默认构造
Manager::Manager()   
{

}

// 有参构造
Manager::Manager(string name, string pwd) 
{
    this->m_name = name;
    this->m_pwd = pwd;
    // 初始化容器，获取所有文件中学生、教师、机房的信息
    this->initVector();

}

// 管理员菜单界面    用多态重写父类接口
void Manager::myMenu()
{
    cout << endl
         << "  ********* 欢迎管理员: " << this->m_name << "登录！ *********" << endl
         << endl;
    cout << "\t--------------------------------" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|          1. 添加账号         |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|          2. 查看账号         |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|          3. 查看机房         |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|          4. 清空预约         |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|          0. 退    出         |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t--------------------------------" << endl
            << endl;

}

void Manager::initVector()
{
    // 确保容器为空
    vs.clear();
    vt.clear();
    vc.clear();
    // 读取学生文件中的数据到学生容器中
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "读取文件失败!" << endl;
        return;
    }
    Student s;
    while (ifs >> s.m_sid && ifs >> s.m_name && ifs >> s.m_pwd)
        vs.push_back(s);
    // cout << "当前学生的数量为: " << vs.size() << endl;
    ifs.close();

    // 读取教师文件中的数据到教师容器中
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "读取文件失败!" << endl;
        return;
    }
    Teacher t;
    while (ifs >> t.m_tid && ifs >> t.m_name && ifs >> t.m_pwd)
        vt.push_back(t);
    // cout << "当前教师的数量为: " << vt.size() << endl;
    ifs.close();

    // 获取机房信息
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "读取文件失败!" << endl;
        return;
    }
    ComputerRoom cr;
    while (ifs >> cr.m_roomId && ifs >> cr.m_maxNum)
        vc.push_back(cr);
    // cout << "当前机房的数量为: " << vc.size() << endl;
    ifs.close();
}

// 检测账号id是否存在
bool Manager::isIdExist(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
        {
            if (id == it->m_sid)   // 该学号已存在
                return true;
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
        {
            if (id == it->m_tid)   // 该教师工号已存在
                return true;
        }
    }
    return false;
}

// 添加账号
void Manager::addPerson()
{
    cout << "请输入添加账号的类型(1.学生  2.教师): ";
    string fileName;
    // string tip;
    ofstream ofs;
    int choice = -1;
    cin >> choice;

    if (choice == 1)
    {
        fileName = STUDENT_FILE;
        cout << "请输入您的学号: ";
    }
    else if (choice == 2)
    {
        fileName = TEACHER_FILE;
        cout << "请输入您的教师工号: ";
    }
    else
    {
        cout << "您的输入类型有误，请按任意键重新输入！" << endl;
        system("pause");
        system("cls");
        return;
    }
    int id;
    string name;
    string pwd;
    while (true)
    {
        cin >> id;
        bool ans = this->isIdExist(id, choice);
        if (ans)
        {
            if (choice == 1)
                cout << "该学号已存在，请重新输入您的学号: ";
            else
                cout << "该教师工号已存在，请重新输入您的教师工号: ";
        }
        else
            break;
    }
    cout << "请输入用户名: ";
    cin >> name;
    cout << "请输入密码: ";
    cin >> pwd;
    // 写数据到文件
    ofs.open(fileName, ios::out | ios::app);
    ofs << id << ' ' << name << ' ' << pwd << ' ' << endl;
    cout << "添加成功!" << endl;
    ofs.close();
    this->initVector();   // 将刚刚添加的账号信息更新，以免账号重复
    system("pause");
    system("cls");
    return;
}

// 查看账号
void Manager::showPeople()
{
    cout << "您想查看哪类账号信息(1.学生 2.教师): ";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        cout << "所有学生信息如下: " << endl;
        for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
            cout << "学  号: " << it->m_sid << "\t用户名: " << it->m_name << "\t密码: " << it->m_pwd << endl;
    }
    else
    {
        cout << "所有教师信息如下: " << endl;
        for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
            cout << "教师工号: " << it->m_tid << "\t用户名: " << it->m_name << "\t密码: " << it->m_pwd << endl;
    }
    system("pause");
    system("cls");
    return;
}

// 查看机房信息
void Manager::showComputerRoom()
{
    cout << "所有机房信息如下: " << endl;
    for (vector<ComputerRoom>::iterator it = vc.begin(); it != vc.end(); it++)
        cout << "机房号: " << it->m_roomId << "\t机房容量: " << it->m_maxNum << endl;
    system("pause");
    system("cls");
    return;
}

// 清空预约记录
void Manager::cleanReservation()
{
    ofstream ofs(RESERVATION_FILE, ios::trunc);  // 以创建的方式打开，如果文件已存在，则先删除再创建
    ofs.close();
    cout << "预约清空成功!" << endl;
    system("pause");
    system("cls");
    return;
}


// 析构函数
Manager::~Manager()
{

}
