#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

// 可调用对象类型（重载了调用运算符的类）
struct myCompare
{
    bool operator ()(const int& a, const int& b)
    {
        return a > b;
    }
};

int main(int argc, char *argv[])
{
#if 0x00
    priority_queue<int> Q;
    Q.push(1);
    Q.push(3);
    Q.push(5);
    Q.push(7);
    Q.push(9);
    cout << "Q size : " << Q.size() << endl;
    int size = Q.size();
    for ( int i = 0; i != size; ++i)
    {
        cout << Q.top() << endl;
        Q.pop();
    }
    cout << endl;
#elif 0xFF
    priority_queue<int, vector<int>, myCompare> Q;
    Q.push(1);
    Q.push(3);
    Q.push(5);
    Q.push(7);
    Q.push(9);
    /*
    while (!Q.empty())
    {
        cout << Q.top() << endl;
        Q.pop();
    }
    */
    for (int i = 0; i != 10; ++i)
        Q.push(i);
    while (!Q.empty())
    {
        cout << Q.top() << endl;
        Q.pop();
    }
#endif
    return 0;
}
