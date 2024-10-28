/*
 * @Description:                    身份抽象类
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 20:29:36
 * @LastEditTime: 2024-10-17 07:59:17
 */
#pragma once
#include <iostream>
using namespace std;

// 身份抽象类（三种身份的共性）
class Identity
{
public:
    string m_name; // 用户名
    string m_pwd;  // 密码

    // 操作菜单    子类用多态去重写父类接口
    virtual void myMenu() = 0; // 纯虚函数

     virtual ~Identity()       // 虚析构函数
     {

     } 
};