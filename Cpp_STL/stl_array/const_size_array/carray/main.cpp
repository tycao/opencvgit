#include <algorithm>
#include "carray.h"
#include "../../../print.h"

int main(int argc, char *argv[])
{
    carray<int, 10> a;

    for (unsigned i = 0; i < a.size(); ++i)
        a[i] = i + 1;

    // print all elements of the carray
    PRINT_ELEMENT(a, "carray : ");


    // reverse all elements of carray
    std::reverse(a.begin(), a.end());
    // print carray after reverse operation
    PRINT_ELEMENT(a, "carray after reverse: ");


    // transform
    std::transform(a.begin(), a.end(),  // source
                   a.begin(),   // destination
                   std::negate<int>()   // operation
                   );
    // print all elements of carray after transform operation
    PRINT_ELEMENT(a, "carray after transform: ");


    // 测试 operator[], 超出数组实际长度，会抛出runtime_error异常
    for (int i = 0; i != a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << a[10] << std::endl;    // carray数组a的下标index最大值为9，共10各元素
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
