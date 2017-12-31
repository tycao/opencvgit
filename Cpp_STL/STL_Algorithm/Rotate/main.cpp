#include <iostream>
#include "rotate.h"

void print(std::vector<std::vector<int>>&);

int main(int argc, char *argv[])
{
    Solution s;

    std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(vec);

    std::cout << "=================\n";
    s.rotate(vec);
    print(vec);


    return 0;
}

void print(std::vector<std::vector<int>>& matrix) {
    for (std::vector<int>& i : matrix)
    {
        for (int& j : i)
            std::cout << j << " ";
        std::cout << "\n";
    }
}
