#pragma once

#include <iostream>
#include <vector>

using namespace std;

class InsertSort
{
public:
    InsertSort(std::vector<int> _list, int _len);   // ¹¹Ôìº¯Êý
    void insert_sort();
    void out();
private:
    int len;
    std::vector<int> list;
};
