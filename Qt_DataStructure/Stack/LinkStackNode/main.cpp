#include <vector>
#include <algorithm>
#include <iostream>
#include <linkstack.h>

using namespace std;

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    LinkStack<int> linkStack;//(100);
    std::for_each(vInt.begin(), vInt.end(), [&](int i){ linkStack.Push(i); });
    //for (int i = 1; i != 10; ++i)
    //   linkStack.Push(i);
    //while (!linkStack.IsEmpty())
     //   cout << linkStack.Pop() << endl;
    if (linkStack.MakeEmpty())
        cout << "oops...make LinkStack empty now..." << endl;

    return 0;
}
