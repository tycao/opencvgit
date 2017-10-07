#pragma once

#include <vector>
#include <iostream>

using namespace std;

// 把迷宫表示为n个有编码路口的集合
// 定义路口类
class Crossings
{
public:
    // 路口的3个方向， ‘0’表示不通
    int turn1;
    int turn2;
    int turn3;
public:
    // 构造函数
    Crossings(int turn1, int turn2, int turn3);
private:

};

