#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        Queue<string> qt;

        // insert 3 elements into the queue
        qt.push("There ");
        qt.push("are ");
        qt.push("more than ");

        // read and print 2 elements from the queue
        cout << qt.pop();
        cout << qt.pop();

        // push 2 new elements
        qt.push("four ");
        qt.push("words!");

        // skip one element
        qt.pop();

        // read anf print two elements from the queue
        cout << qt.pop();
        cout << qt.pop() << endl;

        // print number of remaining elements
        cout << "number of remaining elements in the queue : " << qt.size() << endl;

        // cause exception when pop() with empty queue.
        cout << qt.pop() << endl;
    }
    catch (const Queue<string>::ReadEmptyQueue& e)
    {
        cout << "EXCEPTION : " << e.what() << endl;
    }

    return 0;
}
