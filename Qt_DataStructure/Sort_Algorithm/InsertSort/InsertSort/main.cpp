#include "insertsort.h"

int main(int argc, char *argv[])
{
    // Unit test
    std::vector<int> vInt{1, 3, 5, 2, 6, 9, 7, 4, 8};
    InsertSort sort(vInt, 9);

    sort.insert_sort();
    sort.out();
    return 0;
}
