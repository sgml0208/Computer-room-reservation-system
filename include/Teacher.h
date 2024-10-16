/*
 * @Description:                    教师类
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-16 20:57:58
 * @LastEditTime: 2024-10-16 21:13:22
 */


/*
教师类主要功能是查看学生的预约，并进行审核
教师类中主要功能有:
    显示教师操作的菜单界面
    查看所有预约
    审核预约

*/


// 教师类
#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;


class Teacher : public Identity
{
public:
    int m_tid;      // 教师工号

    Teacher();   // 默认构造
    Teacher(int id, string name, string pwd); // 有参构造

    // 教师菜单界面    用多态重写父类接口
    virtual void myMenu(); 

    // 查看所有预约
    void showAllOrder();

    // 审核预约
    void verifyMyOrder();
    
    
};





