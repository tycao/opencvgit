#pragma once

/*
 * self-defined stack template class, which is much safer and more convenient
*/

#include <deque>
#include <exception>    // 若是自定义自己的异常类，则是包含std::exception，若是这届使用异常类，则包含std::stdexcept

template<typename T>
class Stack
{
protected:
    std::deque<T> c;    // container for the element
public:
    // self-defined exception class for pop() and top() with empty stack
    class ReadEmptyStack : public std::exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "ooops, read empty stack!";
        }
    };

    // number of elements
    typename std::deque<T>::size_type size() const
    {
        return c.size();
    }

    // check if stack is empty?
    bool empty() const
    {
        return c.empty();
    }

    // push element into stack
    void push(const T& elem)
    {
        c.push_back(elem);
    }

    // pop element out of the stack and return its value
    T pop()
    {
        if (c.empty())
            throw ReadEmptyStack();
        T elem(c.back());
        c.pop_back();
        return elem;
    }

    // return value of next element
    T& top()
    {
        if (c.empty())
            throw ReadEmptyStack();
        return c.back();
    }

};
