Array 可以被视为一种STL容器
=================
### 我们也可以把数组当作STL容器使用。但是array并不是类别，所以不提供begin()和end()等成员函数，也不允许存在任何成员函数。在这里我们只能采用非侵入性做法或者包装法。

直接运用数组
------
### 采用非侵入性做法很简单，你只需要一个对象，它能够透过STL迭代器接口，遍历数组的所有元素。事实上这样的对象早就恭候多时了，它就是*普通指针*。STL设计之初就决定让迭代器拥有和普通指针相同的接口，于是你可以将普通指针当成迭代器来使用。这又一次展示了*纯粹抽象的泛化概念*：*行为类似迭代器的任何东西就是一种迭代器。* 事实上，指针正是一个随机存取迭代器。

### 本demo就是示范如何以array作为STL容器。

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