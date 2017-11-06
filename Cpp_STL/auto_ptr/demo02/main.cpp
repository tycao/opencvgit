#include <iostream>
#include <memory>

using namespace std;

/* define output operator for auto_ptr
 * - print object value or NULL
*/
template<typename T>
std::ostream& operator << (std::ostream& os, const std::auto_ptr<T>& p)
{
    // Does p own an object ?
    if (p.get() == nullptr)
        os << "NULL";   // NO: print NULL
    else
        os << *p;   // YES: print the object
    return os;
}


int main(int argc, char *argv[])
{
    const std::auto_ptr<int> p(new int(10));
    const std::auto_ptr<int> q(new int(0));
    const auto_ptr<int> r;

    cout << "after initialization : \n";
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;
    cout << "r : " << r << endl;

    *q = *p;
    //*r = *p;    // Error : undefined behavior (the reason is that r does not own any object)
    *p = -77;

    cout << "after assigning values : \n";
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;
    cout << "r : " << r << endl;

    //q = p;  // Error at compile time : operand types are "const std::auto_ptr<int>", which should be "std::auto_ptr<int>"
    //r = p;  // Error at compile time
    return 0;
}
