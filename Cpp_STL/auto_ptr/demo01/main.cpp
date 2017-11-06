#include <iostream>
#include <memory>

using namespace std;

/*
 * define output operator for auto_ptr
 * - print object value or NULL
*/
template<typename T>
std::ostream& operator << (std::ostream& os, const auto_ptr<T>& p)
{
    // does p own an object ?
    if (p.get() == nullptr)
        os << "NULL";   // NO: print NULL
    else
        os << *p;   // YES: print the object
    return os;
}

int main(int argc, char *argv[])
{
    auto_ptr<int> p(new int(42));
    auto_ptr<int> q;

    cout << "after initialization : \n";
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;

    q = p;
    cout << "after assigning auto pointers: \n";
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;

    *q += 13;   // change value of the object q owns
    p = q;
    cout << "after changing values and reassignment : " << endl;
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;

    return 0;
}
