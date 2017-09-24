#pragma once

#include <iostream>
#include <string>

using namespace std;

class car
{
public:
    car(string, int);   // 默认构造函数
    string getLicence() const;
    int getMovedTimes() const;
    void move();
    virtual ~car(); // 析构函数
private:
    string license;
    int movedTimes;
};



