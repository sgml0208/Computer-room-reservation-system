/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-15 22:15:03
 * @LastEditTime: 2024-10-28 19:27:51
 */

/*
1.2 身份简介
分别有三种身份使用该程序
    学生:申请使用机房
    教师:审核学生的预约申请
    管理员:给学生、教师创建账号

1.3 机房简介
机房总共有3间
    1号机房     最大容量20人
    2号机房     最多容量50人
    3号机房     最多容量100人

1.4 申请简介
申请的订单每周由管理员负责清空。
学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段(上午、下午)
教师来审核预约，依据实际情况审核预约通过或者不通过

1.5 系统具体需求
首先进入登录界面，可选登录身份有:
    学生
    老师
    管理员
    退出

每个身份都需要进行验证后，进入子菜单
    学生需要输入:学号、姓名、登录密码
    老师需要输入:职工号、姓名、登录密码
    管理员需要输入:管理员姓名、登录密码

学生具体功能
    申请预约机房
    查着自身的预约: 查看自己的预约状态
    查看所有预约:   查看全部预约信息以及预约状态
    取消预约:       取消自身的预约，预约成功或审核中的预约均可取消

教师具体功能
查看所有预约: 查看全部预约信息以及预约状态
审核预约:     对学生的预约进行审核
注销登录:     退出登录

管理员具体功能
添加账号:   添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
查看账号:   可以选择查看学生或教师的全部信息
查看机房:   查看所有机房的信息
清空预约:   清空所有预约记录
注销登录:   退出登录

*/

#include <cstring>
#include <fstream>
#include <ctime>
#include <iostream>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include <windows.h>
using namespace std;

// 管理员菜单功能
void managerMenu(Identity *&manager) // 传入父类指针
{
    while (true)
    {
        // 管理员菜单界面
        manager->myMenu();
        // 将父类指针转为子类指针，以便调用子类其他接口
        Manager * man = (Manager *)manager;
        int choice = -1;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // 添加账号
            man->addPerson();
            break;
        case 2: // 查看账号
            man->showPeople();
            break;
        case 3: // 查看机房
            man->showComputerRoom();
            break;
        case 4: // 清空预约
            man->cleanReservation();
            break;
        case 0: // 退出
            cout << "退出成功，欢迎下次使用!" << endl;
            delete manager; // 销毁堆区对象，不能改成delete man，man是局部指针，函数结束也跟着释放了
            manager = nullptr; // 使用nullptr代替NULL，更符合C++标准
            system("pause");
            system("cls");
            return;
        default:
            cout << "您输入的选择有误，请重新输入您的选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}


// 学生菜单功能           atoi(s.c_str()): string -> int
void studentMenu(Identity *&student) // 传入父类指针
{
    while (true)
    {
        // 学生菜单界面
        student->myMenu();
        // 将父类指针转为子类指针，以便调用子类其他接口
        Student * stu = (Student *)student;
        int choice = -1;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // 申请预约
            stu->applyOrder();
            break;
        case 2: // 查看我的预约
            stu->showMyOrder();
            break;
        case 3: // 查看所有预约
            stu->showAllOrder();
            break;
        case 4: // 取消预约
            stu->cancelMyOrder();
            break;
        case 0: // 退出
            cout << "退出成功，欢迎下次使用!" << endl;
            delete student; // 销毁堆区对象
            student = nullptr; // 使用nullptr代替NULL，更符合C++标准
            system("pause");
            system("cls");
            return;
        default:
            cout << "您输入的选择有误，请重新输入您的选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

// 教师菜单功能           
void teacherMenu(Identity *&teacher) // 传入父类指针
{
    while (true)
    {
        // 学生菜单界面
        teacher->myMenu();
        // 将父类指针转为子类指针，以便调用子类其他接口
        Teacher * tea = (Teacher *)teacher;
        int choice = -1;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // 查看所有预约
            tea->showAllOrder();
            break;
        case 2: // 审核预约
            tea->verifyMyOrder();
            break;
        case 0: // 退出
            cout << "退出成功，欢迎下次使用!" << endl;
            delete teacher; // 销毁堆区对象
            teacher = nullptr; // 使用nullptr代替NULL，更符合C++标准
            system("pause");
            system("cls");
            return;
        default:
            cout << "您输入的选择有误，请重新输入您的选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}


// 登录函数
// fileName ---操作的文件名
// type ---登录的身份 (1代表学生、2代表老师、3代表管理员)
void login(string fileName, int type)
{
    // 父类指针，指向子类对象
    Identity *person = NULL; // 利用多态
    ifstream ifs;
    ifs.open(fileName, ios::in);

    // 如果文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在!" << endl;
        ifs.close();
        return;
    }

    int id = -1;
    string name;
    string pwd;

    if (type == 1) // 学生登录
    {
        cout << "请输入您的学号: ";
        cin >> id;
    }
    else if (type == 2) // 教师登录
    {
        cout << "请输入您的教师工号: ";
        cin >> id;
    }
    cout << "请输入您的用户名: ";
    cin >> name;
    cout << "请输入您的密码: ";
    cin >> pwd;
    if (type == 1) // 学生登录验证
    {
        int sid;
        string sname;
        string spwd;
        while (ifs >> sid && ifs >> sname && ifs >> spwd)
        {
            if (id == sid && name == sname && pwd == spwd) // 中文无法通过，需要将txt文件编码换成ANSI格式试试
            {
                cout << "学生验证登录成功! " << endl;
                system("cls");
                person = new Student(id, name, pwd);
                // 进入学生菜单页面
                studentMenu(person);
                return;
            }
        }
    }
    else if (type == 2) // 教师登录验证
    {
        int tid;
        string tname;
        string tpwd;
        while (ifs >> tid && ifs >> tname && ifs >> tpwd)
        {
            if (id == tid && name == tname && pwd == tpwd)
            {
                cout << "教师验证登录成功! " << endl;
                system("cls");
                person = new Teacher(id, name, pwd);
                // 进入教师菜单页面
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3) // 管理员登录验证
    {
        string mname;
        string mpwd;
        while (ifs >> mname && ifs >> mpwd)
        {
            if (name == mname && pwd == mpwd)
            {
                // cout << "管理员验证登录成功! " << endl;
                // system("pause");
                system("cls");
                person = new Manager(name, pwd);
                // 进入管理员菜单页面
                managerMenu(person);
                return;
            }
        }
    }

    cout << "您输入的信息有误，登录失败" << endl;
    system("pause");
    system("cls");
    return;
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(65001); // 设置控制台输出编码为UTF-8

    int choice = -1;

    while (true)
    {
        cout << endl
             << "  ******** 欢迎来到机房预约管理系统 ********" << endl
             << endl;
        cout << "\t------------------------------" << endl;
        cout << "\t|                            |" << endl;
        cout << "\t|          1. 学 生          |" << endl;
        cout << "\t|                            |" << endl;
        cout << "\t|          2. 教 师          |" << endl;
        cout << "\t|                            |" << endl;
        cout << "\t|          3. 管理员         |" << endl;
        cout << "\t|                            |" << endl;
        cout << "\t|          0. 退 出          |" << endl;
        cout << "\t|                            |" << endl;
        cout << "\t------------------------------" << endl
             << endl;

        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            cout << endl
                 << "退出成功，欢迎下次使用!" << endl
                 << endl;
            return 0;
        case 1:                     // 进入学生界面
            login(STUDENT_FILE, 1); // 学生身份验证
            break;
        case 2:                     // 进入教师界面
            login(TEACHER_FILE, 2); // 教师身份验证
            break;
        case 3:                   // 进入管理员界面
            login(ADMIN_FILE, 3); // 管理员身份验证
            break;
        default:
            cout << "输入有误，请重新选择!" << endl;
            system("pause");
            system("cls"); // windows系统的清屏  Unix-like系统(如Linux或macOS)是system("clear");
            break;
        }
    }

    return 0;
}
