/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 20:35:14
 * @LastEditTime: 2024-10-28 19:50:09
 */

#include "Student.h"
#include <iostream>
using namespace std;

// 默认构造
Student::Student()
{
}

// 有参构造
Student::Student(int id, string name, string pwd)
{
    this->m_sid = id;
    this->m_name = name;
    this->m_pwd = pwd;
    this->initVector();
}

// 学生菜单界面
void Student::myMenu()
{
    cout << endl
         << "  *********** 欢迎学生: " << this->m_name << "登录！ ***********" << endl
         << endl;
    cout << "\t--------------------------------" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         1. 申请预约          |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         2. 查看我的预约      |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         3. 查看所有预约      |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         4. 取消预约          |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         0. 退    出          |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t--------------------------------" << endl
         << endl;
}

void Student::initVector()
{
    // 确保容器为空
    vc.clear();
    // 获取机房信息
    ifstream ifs;
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

// 申请预约
void Student::applyOrder()
{
    cout << "机房开放时间是星期一至星期五!" << endl;
    cout << "请输入申请预约的时间(1-5):";
    int date = 0;     // 星期几
    int interval = 0; // 申请时间段
    int room = 0;     // 申请哪个机房
    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
            break;
        cout << "输入错误，机房开放时间是星期一至星期五！请重新输入: ";
    }
    cout << "请输入申请预约的时间段(1.上午 2.下午): ";
    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
            break;
        cout << "输入错误，只能申请上午或下午，请重新输入: ";
    }
    cout << "请输入申请的是机房号(1, " << vc.size() << "): ";
    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= vc.size())
            break;
        cout << "输入错误，没有您输入的机房号，请重新输入: ";
    }

    cout << "预约成功! 审核中" << endl; // 后续如果改进可以显示当前每个机房的剩余容量和座位号情况
    // 将预约信息写入预约文件
    ofstream ofs(RESERVATION_FILE, ios::app);
    ofs << "date(Monday-Friday):" << date << "\t\t";
    ofs << "interval(1.morning,2.afternoon):" << interval << "\t\t";
    ofs << "stuId:" << this->m_sid << "\t\t";
    ofs << "stuName:" << this->m_name << "\t";
    ofs << "roomId:" << room << "\t";
    ofs << "status:" << 1 << endl; // 当前预约状态为 审核中   (还有审核成功和审核失败)
    ofs.close();
    system("pause");
    system("cls");
    return;
}

// 查看我的预约
void Student::showMyOrder()
{
    ShowOrder order;
    if (order.m_orderNum == 0)
    {
        cout << "没有预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }
    int order_num = 0;
    string myDate[5] = {"周一", "周二", "周三", "周四", "周五"};
    for (int i = 0; i < order.m_orderNum; i++)
    {
        if (atoi(order.m_orderData[i]["stuId"].c_str()) == this->m_sid) // atoi(s.c_str()): string -> int
        {
            cout << "您的第" << ++order_num << "条预约信息如下: " << endl; // stoi: string -> int
            cout << "预约日期: " << myDate[atoi((order.m_orderData[i]["date(Monday-Friday)"].c_str())) - 1];
            cout << (order.m_orderData[i]["interval(1.morning,2.afternoon)"] == "1" ? "上午" : "下午") << endl;
            cout << "机房号为: " << order.m_orderData[i]["roomId"] << endl;
            string status = "预约状态: "; // 0: 已取消  1: 审核中  2: 已预约  -1: 预约失败
            if (order.m_orderData[i]["status"] == "1")
                status += "审核中";
            else if (order.m_orderData[i]["status"] == "2")
                status += "预约成功";
            else if (order.m_orderData[i]["status"] == "-1")
                status += "预约失败";
            else
                status += "已取消该预约";
            cout << status << endl
                 << endl;
        }
    }
    system("pause");
    system("cls");
    return;
}

// 查看所有预约
void Student::showAllOrder()
{
    ShowOrder order;
    if (order.m_orderNum == 0)
    {
        cout << "没有预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }
    string myDate[5] = {"周一", "周二", "周三", "周四", "周五"};
    cout << "一共有" << order.m_orderNum << "条预约!" << endl;
    for (int i = 0; i < order.m_orderNum; i++)
    {
        cout << "预约日期: " << myDate[atoi((order.m_orderData[i]["date(Monday-Friday)"].c_str())) - 1];
        cout << (order.m_orderData[i]["interval(1.morning,2.afternoon)"] == "1" ? "上午" : "下午") << endl;
        cout << "机房号为: " << order.m_orderData[i]["roomId"] << endl;
        cout << "预约人学号: " << order.m_orderData[i]["stuId"] << endl;
        cout << "预约人姓名: " << order.m_orderData[i]["stuName"] << endl;
        string status = "预约状态: "; // 0: 已取消  1: 审核中  2: 已预约  -1: 预约失败
        if (order.m_orderData[i]["status"] == "1")
            status += "审核中";
        else if (order.m_orderData[i]["status"] == "2")
            status += "预约成功";
        else if (order.m_orderData[i]["status"] == "-1")
            status += "预约失败";
        else
            status += "已取消该预约";
        cout << status << endl
             << endl;
    }
    system("pause");
    system("cls");
    return;
}

// 取消我的预约
void Student::cancelMyOrder()
{
    ShowOrder order;
    if (order.m_orderNum == 0)
    {
        cout << "没有预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "审核中或预约成功的记录可取消，可以取消的记录有: " << endl;
    vector<int> v;
    int index = 1;
    int choice = -1;
    string myDate[5] = {"周一", "周二", "周三", "周四", "周五"};
    for (int i = 0; i < order.m_orderNum; i++)
    {
        if (atoi(order.m_orderData[i]["stuId"].c_str()) == this->m_sid)
        {
            if (order.m_orderData[i]["status"] == "1" | order.m_orderData[i]["status"] == "2")
            {
                v.push_back(i);
                cout << "第" << index++ << "条预约: ";
                cout << "预约日期: " << myDate[atoi((order.m_orderData[i]["date(Monday-Friday)"].c_str())) - 1];
                cout << (order.m_orderData[i]["interval(1.morning,2.afternoon)"] == "1" ? "上午" : "下午") << "\t";
                cout << "机房号为: " << order.m_orderData[i]["roomId"] << "\t";
                string status = "预约状态: "; // 0: 已取消  1: 审核中  2: 已预约  -1: 预约失败
                if (order.m_orderData[i]["status"] == "1")
                    status += "审核中";
                else
                    status += "预约成功";
                cout << status << endl;
            }
        }
    }
    if (v.size() == 0)
        cout << "没有可以取消的预约!" << endl;
    else
    {
        cout << "请输入您想要取消的预约记录的编号(0代表返回): ";
        while (true)
        {
            cin >> choice;
            char ch;
            if (choice >= 0 && choice <= v.size())
            {
                if (choice == 0)
                    break;
                cout << "确定取消该预约?(y/n): ";
                cin >> ch;
                if (ch == 'y')
                {
                    order.m_orderData[v[choice - 1]]["status"] = "0";   // 改为已取消
                    order.updateOrder();   // 更新
                    cout << "已成功取消该预约!" << endl;
                }
                else
                    cout << "已取消该操作!" << endl;
                break;
            }
            else
                cout << "输入的编号有误!请重新输入: ";
        }
    }

    system("pause");
    system("cls");
    return;
}

// 默认析构函数
Student::~Student()
{
}
