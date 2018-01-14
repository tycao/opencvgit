#include "self_defined_allocator.h"
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    vector<int, my_allocator<int>> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    for (auto i : vInt)
        cout << i << " ";
    cout << "\n";

    return 0;
}
