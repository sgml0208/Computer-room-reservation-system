/*
 * @Description:                    显示预约
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-28 15:02:08
 * @LastEditTime: 2024-10-28 15:10:35
 */




#pragma once
#include "globalFile.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

// 学生类
class ShowOrder
{
public:
    ShowOrder();
    
    // 更新预约记录(更新status)
    void updateOrder();
    
    // 记录的容器，key---预约的条数，value---具体记录的键值对信息
    map<int, map<string, string>> m_orderData;

    // 记录预约的条数
    int m_orderNum;

    ~ShowOrder();
};