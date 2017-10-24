#if 0
// Unit Test
#include "item.h"
#endif

#include <string>
#include "ordersearch.h"

int main(int argc, char *argv[])
{
#if 0
    // Unti Test
    Item<int> item(9, 99);
    cout << item << endl;
#elif 1
    OrderSearch<std::string> os(10);

    os.Add(Item<std::string>(0, "Hi Mom!"));
    os.Add(Item<std::string>(1, "Hi Dad!"));
    os.Add(Item<std::string>(2, "Hi son!"));
    os.Add(Item<std::string>(3, "Hi daughter!"));
    os.Add(Item<std::string>(4, "Hi grandpa!"));
    os.Add(Item<std::string>(5, "Hi grandma!"));
    os.Add(Item<std::string>(6, "Hi Son-in-law!"));
    os.Add(Item<std::string>(7, "Hi daughter-in-law!"));
    os.Add(Item<std::string>(8, "Hi Mom-in-law!"));
    os.Add(Item<std::string>(9, "Hi Dad-in-law!"));

    cout << os << endl;
    cout << os.GetSize() << endl
         << os.GetContain()->GetKey() << " : "
         << os.GetContain()->GetData() << endl;
    cout << os.search(9) << endl;

#endif

    return 0;
}
