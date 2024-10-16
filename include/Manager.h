/*
 * @Description:                        管理员类
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 21:04:26
 * @LastEditTime: 2024-10-16 21:08:53
 */


/*
管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录
管理员类中主要功能有:
    显示管理员操作的菜单界面
    添加账号
    查看账号
    查看机房信息
    清空预约记录

*/


#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;

// 学生类
class Manager : public Identity
{
public:
    Manager();   // 默认构造
    Manager(string name, string pwd); // 有参构造

    // 管理员菜单界面    用多态重写父类接口
    virtual void myMenu(); 

    // 添加账号
    void addPerson();

    // 查看账号
    void showPerson();

    // 查看机房信息
    void showComputerRoom();

    // 清空预约记录
    void cleanReservation();
    
    
};
