#include <cctype>   // for toupper()
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

#include "adapter.h"

using namespace std;

int main(int argc, char *argv[])
{
    string s("Internationalization");
    string sub("Nation");

    // search substring case insensitive
    string::iterator pos;
    pos = search (s.begin(), s.end(),   // string to search in
                  sub.begin(), sub.end(), // substring to search
                  compose_f_gx_hy(equal_to<int>(),
                                  ptr_fun(::toupper),
                                  ptr_fun(::toupper)));
    if (pos != s.end())
        cout << "\"" << sub << "\" is part of \"" << s << "\""
             << endl;
    return 0;
}
