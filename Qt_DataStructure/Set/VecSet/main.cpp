#include <iomanip>
#include "vecset.h"

int main(int argc, char *argv[])
{
    VecSet vSet1(10);
    VecSet vSet2(10);

    vSet1.Add(0);
    vSet1.Add(1);
    vSet1.Add(2);
    vSet1.Add(3);
    vSet1.Add(4);
    vSet1.Add(5);
    vSet1.Add(6);
    vSet1.Add(7);
    vSet1.Add(8);
    vSet1.Add(9);

    vSet2.Add(0);
    vSet2.Add(1);
    vSet2.Add(2);
    vSet2.Add(3);
    vSet2.Add(4);
    vSet2.Add(5);
    vSet2.Add(6);
    vSet2.Add(7);
    vSet2.Add(8);
    vSet2.Add(9);

    vSet1.Del(0);
    vSet2.Del(0);

    for (int i = 0; i != vSet1.GetSize(); ++i)
        cout << left << setw(5) << vSet1.GetAt(i) << " ";
    cout << "\n";
    for (int i = 0; i != vSet1.GetSize(); ++i)
        cout << left << setw(5) << vSet2.GetAt(i) << " ";
    cout << "\n";

    if (vSet1 == vSet2)
        cout << "两个集合相等！" << endl;
    else
        cout << "两个集合不相等！" << endl;


    vSet1 * vSet2;
    for (int i = 0; i != vSet1.GetSize(); ++i)
        cout << left << setw(5) << vSet1.GetAt(i) << " ";
    cout << "\n";

    vSet1.MakeEmpty();
    for (int i = 0; i != vSet1.GetSize(); ++i)
        cout << left << setw(5) << vSet1.GetAt(i) << " ";
    cout << "\n";

    for (int i = 0; i != vSet2.GetSize(); ++i)
        cout << left << setw(5) << vSet2.GetAt(i) << " ";
    cout << "\n";

    vSet2 = vSet1;
    for (int i = 0; i != vSet2.GetSize(); ++i)
        cout << left << setw(5) << vSet2.GetAt(i) << " ";
    cout << "\n";


    return 0;
}
