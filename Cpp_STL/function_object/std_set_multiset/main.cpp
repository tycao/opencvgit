#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    set<int> sInt;

    sInt.insert(1);
    sInt.insert(2);
    sInt.insert(4);
    sInt.insert(5);
    sInt.insert(6);

    cout << "lower_bound(3) : " << *sInt.lower_bound(3) << endl;
    cout << "upper_bound(3) : " << *sInt.upper_bound(3) << endl;
    cout << "equal_range(3) : " << *sInt.equal_range(3).first << " "
         << *sInt.equal_range(3).second << endl;

    cout << "\n\n";
    cout << "lower_bound(5) : " << *sInt.lower_bound(5) << endl;
    cout << "upper_bound(5) : " << *sInt.upper_bound(5) << endl;
    cout << "euqal_range(5) : " << *sInt.equal_range(5).first << " "
         << *sInt.equal_range(5).second << endl;
    return 0;
}
