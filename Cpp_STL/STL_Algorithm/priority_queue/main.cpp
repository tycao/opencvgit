#include <iostream>
#include <algorithm>    // for make_heap()
#include "priority_queue.h"

using namespace std;

int main(int argc, char *argv[])
{
    priority_queue<float> q;

    // push 3 elements into the queue
    q.push(22.2);
    q.push(11.1);
    q.push(66.6);

    // read and print two elements
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();

    // insert three more elements
    q.push(44.4);
    q.push(55.5);
    q.push(33.3);

    // skip one element
    q.pop();

    // pop and print remaining elements
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";

    // check if there is any exception thrown.
    q.pop();
    q.pop();
    q.pop();
    q.pop();


    q.top();
    q.top();
    q.top();
    q.top();

    return 0;
}
