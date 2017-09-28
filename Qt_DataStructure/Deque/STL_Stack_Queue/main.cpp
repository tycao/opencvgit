#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

bool existOrNot(int num, queue<int> myQueue)
{
    while (!myQueue.empty())
    {
        if (myQueue.front() == num)
            return true;
        myQueue.pop();
    }
    return false;
}

int main(int argc, char *argv[])
{
#if 0x00
    // 栈 ：先进后出（后进先出）|| FILO（LIFO）
    stack<int> myStack;
    // 入栈和出栈
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    cout << myStack.size() << endl;
    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }
#elif 0x00
    stack<string> myStack;
    ifstream in;
    in.open("c:/list.txt");
    if (!in)
    {
        cerr << "Can not open file for input!" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        string line;
        while (getline(in, line))
            myStack.push(line);
        in.close();
    }
    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }

#elif 0x00  // 十六进制0xFF ：十进制255
    queue<int> myQueue;
    // 添加与删除元素
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);

    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;
    cout << myQueue.size() << endl;
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
#elif 0x00
    queue<int> memQueue;
    int page[] = {4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5};
    int times = 12;
    int tempVal;
    for (int i = 0; i != 12; ++i)
    {
        if (memQueue.size() < 3)
            memQueue.push(page[i]);
        else
        {
            if (existOrNot(page[i], memQueue))
                --times;
            else
            {
                memQueue.pop();
                memQueue.push(page[i]);
            }
        }
        int size = memQueue.size();
        while (size > 0)
        {
            cout << memQueue.front() << " ";
            tempVal = memQueue.front();
            memQueue.pop();
            memQueue.push(tempVal);
            --size;
        }
        cout << endl;
    }
    cout << "when using FIFO strategy, paging missing happens totally " << times << " times." << endl;
#elif 0xFF

#endif

    return 0;
}
