#include "binaryinsertsort.h"

int main(int argc, char *argv[])
{
    // Unit Test
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 13, 15, 17, 19};
    BinaryInsertSort binSort(vInt, 13);
    binSort.binary_insert_sort();
    binSort.out();
    return 0;
}
