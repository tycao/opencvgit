#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char c = ' ';

    // while it is possible to read a character
    while (cin.get(c)) {
        // print it
        cout.put(c);
    }


    return 0;
}
