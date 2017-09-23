#include <vector>
#include <algorithm>
#include <iostream>
#include <linkstack.h>

using namespace std;

int main(int argc, char *argv[])
{
#if 0
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    LinkStack<int> linkStack;//(100);
    std::for_each(vInt.begin(), vInt.end(), [&](int i){ linkStack.Push(i); });
    //for (int i = 1; i != 10; ++i)
    //   linkStack.Push(i);
    //while (!linkStack.IsEmpty())
     //   cout << linkStack.Pop() << endl;
    if (linkStack.MakeEmpty())
        cout << "oops...make LinkStack empty now..." << endl;
#endif
#if 1
    cout << "请输入括号序列，以0结束：";
    LinkStack<char> small('(');
    char c;
    do
    {
        cin >> c;
        switch (c)
        {
        case '(':
            small.Push(c);
            break;
        case ')':
            if (small.IsEmpty())
            {
                cout << "Wrong!" << endl;
                return 0;
            }
            else
                small.Pop();
            break;
        }
    } while (c != '0');
    if (small.IsEmpty())
        cout << "OK" << endl;
    else
        cout << "Wrong" << endl;
#endif

    return 0;
}
