Stream(流)迭代器
========
#### 流迭代器是一种迭代器适配器，通过它，你可以把stream当成算法的原点和终点。更明确地说，*一个istream迭代器，可用来从标准输入中读取元素，而一个ostream迭代器，可用来对标准输出写入元素。*

### std::ostream_iterator<int> intWrite(std::cout, "\n");
![ostream_output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/Stream_Iterator/src/ostream_output.png "ostream_output")

### std::istream_iterator<int> intRead(std::cin);
![istream_output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/Stream_Iterator/src/istream_output.png "istream_output")

### 输入流 和 输出流 
![iostream_output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/Stream_Iterator/src/iostream_output.png "iostream_output")