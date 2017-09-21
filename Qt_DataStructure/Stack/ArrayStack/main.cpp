#include <iostream>
#include <algorithm>
#include <vector>
#include "arraylist.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArrayStack<int> IntStack(10);
    std::vector<int> vecInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    std::for_each(vecInt.begin(), vecInt.end(), [&](int i){ IntStack.Push(i); });
    //cout << IntStack.GetTop() << endl;
    //for_each(vecInt.begin(), vecInt.end(), [&](int& i){ cout << IntStack.Pop() << endl; });

    if (IntStack.MakeEmpty())
        if (IntStack.IsEmpty())
            cout << "oops...ArrayStack is empty now..." << endl;



    return 0;
}
