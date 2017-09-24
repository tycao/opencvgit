#include <iostream>
#include <algorithm>
#include "cirqueue.h"

using namespace std;


int main(int argc, char *argv[])
{
    CirQueue<int> cirQueue(10);
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
#if 0
    std::for_each(vInt.begin(), vInt.end(), [&](int i){ cirQueue.EnQueue(i); });
    std::for_each(vInt.begin(), vInt.end(), [&](int& i){ cout << cirQueue.GetFront() << endl; cirQueue.DelQueue(); });
    assert(cirQueue.IsEmpty());
#endif
    //for_each(vInt.begin(), vInt.end(), [&](int i){ cirQueue.EnQueue(i); });
    //for (int i = 0; i != 10; ++i)
    //    cirQueue.EnQueue(i);
    for (std::vector<int>::iterator iter = vInt.begin(); iter != vInt.end(); ++iter)
        cirQueue.EnQueue(*iter);
    for (auto i = vInt.begin(); i != vInt.end(); ++i)
    {
        cout << cirQueue.GetFront() << "\n";
        cirQueue.DelQueue();
    }
    return 0;
}
