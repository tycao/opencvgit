#pragma once

#include <vector>
#include <iostream>

using namespace std;

// 这是一个全局函数，可能在此工程里，有很多文件需要用到这两个函数
// 因此要先声明这两个全局函数，然后再在实现文件里去实现它们
int binarySearch(const std::vector<int>& a, const int& x, int low, int high);

int Search(const vector<int>& a, const int& x);
