#include <vector>
#include <algorithm>
#include "iterator.h"

int main(int argc, char *argv[])
{
    Iterator<int> a;
    DouList<int> doulist(10000);
    std::vector<int> vecInt = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    for_each(vecInt.begin(), vecInt.end(), [&doulist](int i){ doulist.AddTail(i); });

    // Test1 : DESC
    a = doulist.GetTail();
    while (a != doulist.GetHead())
    {
        cout << a--;
    }

    cout << endl << endl;

    // Test2 : ASC
    a = doulist.GetHead();
    while (a != doulist.GetTail())
    {
        cout << ++a;
    }
    return 0;
}
