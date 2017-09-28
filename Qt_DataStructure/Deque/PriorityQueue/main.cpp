#include <vector>
#include <iostream>
#include <algorithm>

#include "priqueue.h"

using namespace std;

int main(int argc, char *argv[])
{
    PriQueue<int> priQueue;
    std::vector<int> vInt = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 18, 12, 25, 21, 23};
    std::for_each(vInt.begin(), vInt.end(), [&](int i){ priQueue.EnQueue(i); });
    std::for_each(vInt.begin(), vInt.end(), [&](int& i){ cout << priQueue.DelQueue() << " "; });
    return 0;
}
