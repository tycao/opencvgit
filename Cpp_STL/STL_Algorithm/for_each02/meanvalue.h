#pragma once

// function object to process the mean value
class MeanValue
{
public:
    // constructor
    MeanValue()
        : num(0), sum(0)
    {}

    // function call operator overloading
    void operator ()(int elem)
    {
        ++num;  // increment count
        sum += elem;    // add value "elem"
    }

    // 转换构造函数
    operator double()
    {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
private:
    long num;   // number of elements
    long sum;   // sum of all elements values
};
