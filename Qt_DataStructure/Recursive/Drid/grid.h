#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#define INFECTED true
//#define NOT_INFECTED false
constexpr bool INFECTED = true;
constexpr bool NOT_INFECTED = false;

class grid;
std::ostream& operator <<(ostream&, const grid&);

class grid
{
    friend ostream& operator <<(ostream& stream, const grid& ob);
public:
    // 构造函数
    grid(int* theCity, int, int, int);
    ~grid();    // 析构函数
    int count(int row, int col);

private:
    // 私有数据成员
    int indexof(int, int) const;
    bool infected(int row, int col) const;
    void caculate(int row, int col);

    int rows;
    int cols;
    int number;
    vector<bool> * area;
    vector<bool> * marked_area;
};
