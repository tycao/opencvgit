#include <vector>
#include <algorithm>
#include "listset.h"

int main(int argc, char *argv[])
{
    ListSet<int> set1;
    std::vector<int> vInt{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each(vInt.begin(), vInt.end(), [&](int i){ set1.Add(i); });
    cout << set1 << endl;

    set1.Del(1);
    cout << set1 << endl;

    std::vector<int> vInt2{2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each(vInt2.begin(), vInt2.end(), [&](int i){ set1.Del(i); });

    if (set1.IsEmpty())
        cout << "set1 is an empty set!\n";
    else
        cout << set1 << endl;

    return 0;
}
