#include <algorithm>
#include <iostream>
#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vec{9, 9, 9, 9};
    Solution s;
    s.plusOne(vec);
    //for_each(vec.begin(), vec.end(), [&](int& i){ cout << i << " "; });
    for (auto i : vec)
        cout << i << " ";

    return 0;
}
