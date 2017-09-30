#include "binarysearch.h"


int binarySearch(const std::vector<int>& a, const int& x, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    // 二分查找法的递归核心部分
    if (a[mid] > x)
        binarySearch(a, x, low, mid - 1);
    else if (a[mid] < x)
        binarySearch(a, x, mid + 1, high);
    else
        return mid;
}

int Search(const vector<int>& a, const int& x)
{
    return binarySearch(a, x, 0, a.size() - 1);
}
