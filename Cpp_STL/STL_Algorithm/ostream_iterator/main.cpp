#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    copy(istream_iterator<string>(cin), // begining of source
         istream_iterator<string>(),    // end of source
         ostream_iterator<string>(cout, "\n")); // destination
    return 0;
}
