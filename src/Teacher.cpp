/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 20:58:04
 * @LastEditTime: 2024-10-28 19:56:55
 */

#include "Teacher.h"
#include <iostream>
using namespace std;

// 默认构造
Teacher::Teacher()
{
}

// 有参构造
Teacher::Teacher(int id, string name, string pwd)
{
    this->m_tid = id;
    this->m_name = name;
    this->m_pwd = pwd;
}

// 教师菜单界面    用多态重写父类接口
void Teacher::myMenu()
{
    cout << endl
         << "  *********** 欢迎教师: " << this->m_name << "登录！ ***********" << endl
         << endl;
    cout << "\t--------------------------------" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         1. 查看所有预约      |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         2. 审核我的预约      |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|         0. 退    出          |" << endl;
    cout << "\t|                              |" << endl;
    cout << "\t--------------------------------" << endl
         << endl;
}

// 查看所有预约
void Teacher::showAllOrder()
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

// 审核预约
void Teacher::verifyMyOrder()
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
    cout << "待审核的预约信息如下: " << endl;
    vector<int> v;
    int index = 1;
    int choice = -1;
    int ans = -1;
    for (int i = 0; i < order.m_orderNum; i++)
    {
        if (order.m_orderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << "第" << index++ << "条预约: ";
            cout << "预约日期: " << myDate[atoi((order.m_orderData[i]["date(Monday-Friday)"].c_str())) - 1];
            cout << (order.m_orderData[i]["interval(1.morning,2.afternoon)"] == "1" ? "上午" : "下午") << "\t";
            cout << "机房号为: " << order.m_orderData[i]["roomId"] << "\t";
            cout << "预约人学号: " << order.m_orderData[i]["stuId"] << "\t";
            cout << "预约人姓名: " << order.m_orderData[i]["stuName"] << "\t";
            cout << "预约状态: 审核中" << endl;
        }
    }

    if (v.size() == 0)
        cout << "没有需要审核的预约!" << endl;
    else
    {
        cout << "请输入您想要审核的预约记录的编号(0代表返回): ";
        while (true)
        {
            cin >> choice;
            if (choice >= 0 && choice <= v.size())
            {
                if (choice == 0)
                    break;
                cout << "请输入审核结果(1.通过 0.不通过): ";
                cin >> ans;
                if (ans == 1)
                    order.m_orderData[v[choice - 1]]["status"] = "2";
                else
                    order.m_orderData[v[choice - 1]]["status"] = "-1";
                order.updateOrder(); // 更新
                cout << "该预约已审核!" << endl;
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