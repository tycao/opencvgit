#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const string delims(" \t,.;");
    string line;

    // for every line, read successfully
    while (getline(cin, line))
    {
        string::size_type begIdx, endIdx;

        // search begining of the first word
        begIdx = line.find_first_not_of(delims);

        // while begining of the first word found
        while (begIdx != string::npos)
        {
            // search end of the actual word
            endIdx = line.find_first_of(delims, begIdx);
            if (endIdx == string::npos)
            {
                // in this case, end of word is end of line
                endIdx = line.length();
            }

            // print characters in reverse order
            for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i)
            {
                cout << line[i];
            }
            cout << ' ';

            // search begining of the next word
            begIdx = line.find_first_not_of(delims, endIdx);
        }
        cout << endl;
    }
    return 0;
}
