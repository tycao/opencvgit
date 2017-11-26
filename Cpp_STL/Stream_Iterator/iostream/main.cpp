#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    istream_iterator<string> cinPos(cin);
    ostream_iterator<string> coutPos(cout, " ");

    // while input is not at the end of the file, write every third string
    while (cinPos != istream_iterator<string>())
    {
        // ignore the following two strings
        advance(cinPos, 2);

        // read and write the third string
        if (cinPos != istream_iterator<string>())
            *coutPos++ = *cinPos++;
    }
    cout << endl;

    return 0;
}
