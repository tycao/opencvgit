#pragma once

// function object that adds the value with which it is initialized
template<typename T>
class AddValue
{
public:
    // constructor
    AddValue(const T& v)
        : value(v)
    {

    }

    // function call operator overloading
    void operator ()(T& elem) const
    {
        elem += value;
    }
private:
    T value;    // value to add
};
