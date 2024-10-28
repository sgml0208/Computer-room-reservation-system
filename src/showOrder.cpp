/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-10-28 15:02:30
 * @LastEditTime: 2024-10-28 19:09:14
 */

#include "showOrder.h"

// 构造函数
ShowOrder::ShowOrder()
{
    ifstream ifs;
    ifs.open(RESERVATION_FILE, ios::in);

    string order_date;  // 日期
    string interval;    // 时间段
    string stuId;       // 学生编号
    string stuName;     // 学生姓名
    string roomId;      // 机房编号
    string status;      // 预约状态

    this->m_orderNum = 0;  // 预约记录的个数

    while (ifs >> order_date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        // test
        // cout << "date(Monday-Friday): " << order_date << endl;
        // cout << "interval(1.morning, 2.afternoon): " << interval << endl;
        // cout << "stuId: " << stuId << endl;
        // cout << "stuName: " << stuName << endl;
        // cout << "roomId: " << roomId << endl;
        // cout << "status: " << status << endl;

        string key;
        string value;
        map<string, string> m;

        int pos = order_date.find(":");
        if (pos != -1);
        {
            key = order_date.substr(0, pos);
            value = order_date.substr(pos + 1, order_date.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        pos = interval.find(":");
        if (pos != -1);
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        pos = stuId.find(":");
        if (pos != -1);
        {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        pos = stuName.find(":");
        if (pos != -1);
        {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        pos = roomId.find(":");
        if (pos != -1);
        {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        pos = status.find(":");
        if (pos != -1);
        {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // 小容器放大容器中
        this->m_orderData.insert(make_pair(this->m_orderNum, m));
        this->m_orderNum++;
    }
    ifs.close();

    // test
    // cout << "预约记录一共有" << this->m_orderNum << "条!" << endl;
    // for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
    // {
        
    //     for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
    //         cout << "key = " << mit->first << "\tvalue = " << mit->second << endl;
    //     cout << endl;
    // }
    
}

// 更新预约记录(更新status)
void ShowOrder::updateOrder()
{
    if (this->m_orderNum == 0)
    {
        cout << "没有预约记录!" << endl;
        return;
    }
    ofstream ofs(RESERVATION_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_orderNum; i++)
    {
        ofs << "date(Monday-Friday):" << this->m_orderData[i]["date(Monday-Friday)"] << "\t\t";
        ofs << "interval(1.morning,2.afternoon):" << this->m_orderData[i]["interval(1.morning,2.afternoon)"] << "\t\t";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << "\t\t";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << "\t";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << "\t";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    ofs.close();
}

// 析构函数
ShowOrder::~ShowOrder()
{

}