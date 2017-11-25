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


    // ���� operator[], ��������ʵ�ʳ��ȣ����׳�runtime_error�쳣
    for (int i = 0; i != a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << a[10] << std::endl;    // carray����a���±�index���ֵΪ9����10��Ԫ��
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
