/*
 * @Description:                        管理员类
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 21:04:26
 * @LastEditTime: 2024-10-21 12:32:35
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
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
#include "globalFile.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 学生类
class Manager : public Identity
{
public:
    // 学生容器
    vector<Student> vs;
    // 教师容器
    vector<Teacher> vt;
    // 机房容器
    vector<ComputerRoom> vc;

    Manager();   // 默认构造
    Manager(string name, string pwd); // 有参构造

    // 管理员菜单界面    用多态重写父类接口
    virtual void myMenu(); 

    // 初始化容器
    void initVector();

    // 检测账号id是否存在
    bool isIdExist(int id, int type);

    // 添加账号
    void addPerson();

    // 查看账号信息
    void showPeople();

    // 查看机房信息
    void showComputerRoom();

    // 清空预约记录
    void cleanReservation();
    
    ~Manager();   // 析构函数
};
