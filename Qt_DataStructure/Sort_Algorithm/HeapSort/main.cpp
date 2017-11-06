#include "heapsort.h"

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 13, 15, 17, 19, 21, 25, 27, 29};
    HeapSort sort(vInt, 17);
    sort.heap_sort();
    sort.out();

    return 0;
}
