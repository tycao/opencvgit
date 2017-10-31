#include "selectsort.h"

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 15, 17, 29, 18, 53, 34, 27};
    SelectSort sort(vInt, 17);
    sort.select_sort();
    sort.out();

    return 0;
}
