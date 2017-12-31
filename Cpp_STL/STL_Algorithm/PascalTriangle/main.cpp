#include <iostream>
#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    Solution s;

    auto vec = s.generate(5);
    for (vector<int>& i : vec)
    {
        for (int& j : i)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
