#pragma once

#include <iostream>
#include <string>

using namespace std;

class car
{
public:
    car(string, int);   // Ĭ�Ϲ��캯��
    string getLicence() const;
    int getMovedTimes() const;
    void move();
    virtual ~car(); // ��������
private:
    string license;
    int movedTimes;
};



