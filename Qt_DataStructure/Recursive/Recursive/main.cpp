#include "binarysearch.h"

int main(int argc, char *argv[])
{
    std::vector<int> box;
    box.push_back(1);
    box.push_back(4);
    box.push_back(6);
    box.push_back(9);
    box.push_back(16);
    box.push_back(19);
    box.push_back(21);
    box.push_back(25);
    box.push_back(28);
    box.push_back(31);
    box.push_back(39);
    constexpr int searchValue = 29;
    int result = Search(box, searchValue);
    if (result == -1)
        std::cout << searchValue << " was not found in the vector!" << std::endl;
    else
        std::cout << searchValue << "\'s position is at " << ++result << " in this vector." << std::endl;

    return 0;
}
