/*
 * @Description:                    学生类
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 20:35:07
 * @LastEditTime: 2024-10-16 21:13:07
 */



/*
学生类主要功能是可以通过类中成员函数，实现预约实验室操作
学生类中主要功能有:
    显示学生操作的菜单界面
    申请预约
    查看自身预约
    查看所有预约
    取消预约

*/

#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;

// 学生类
class Student : public Identity
{
public:
    int m_sid;      // 学号

    Student();   // 默认构造
    Student(int id, string name, string pwd); // 有参构造

    // 学生菜单界面    用多态重写父类接口
    virtual void myMenu(); 

    // 申请预约
    void applyOrder();

    // 查看我的预约
    void showMyOrder();

    // 查看所有预约
    void showAllOrder();
    
    
};