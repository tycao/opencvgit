#include "shellsort.h"

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 13, 15, 17};
    ShellSort sort(vInt, 13);
    sort.shell_sort();
    sort.out();

    return 0;
}
