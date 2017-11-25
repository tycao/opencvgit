Array ���Ա���Ϊһ��STL����
=================
### ����Ҳ���԰����鵱��STL����ʹ�á�����array������������Բ��ṩbegin()��end()�ȳ�Ա������Ҳ����������κγ�Ա����������������ֻ�ܲ��÷��������������߰�װ����

ֱ����������
------
### ���÷������������ܼ򵥣���ֻ��Ҫһ���������ܹ�͸��STL�������ӿڣ��������������Ԫ�ء���ʵ�������Ķ�����͹����ʱ�ˣ�������*��ָͨ��*��STL���֮���;����õ�����ӵ�к���ָͨ����ͬ�Ľӿڣ���������Խ���ָͨ�뵱�ɵ�������ʹ�á�����һ��չʾ��*�������ķ�������*��*��Ϊ���Ƶ��������κζ�������һ�ֵ�������* ��ʵ�ϣ�ָ������һ�������ȡ��������

### ��demo����ʾ�������array��ΪSTL������

### tree of the demo:
![array](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/array/src/array.png "array")

### screenshot of the demo:
![main_cpp](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/array/src/main_cpp.png "main_cpp")
### main.cpp
```cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator> // for ostream_iterator

using namespace std;

int main(int argc, char *argv[])
{
    int coll[] = {5, 6, 2, 4, 1, 3};

    // square all elements
    std::transform(coll, coll + 6,  // first source
                   coll,    // second source
                   coll,    // destination
                   multiplies<int>()    // operation
                   );

    // sort beginning with the second element
    sort(coll + 1, coll + 6);

    // print all elements
    std::copy(coll, coll + 6,
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << endl;
    return 0;
}
```

### output of the demo:
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/array/src/output.png "output")