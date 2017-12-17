#pragma once

/*
 * much safer and more convenient Queue template class
*/
#include <deque>
#include <exception>

template<typename T>
class Queue
{
protected:
    std::deque<T> c;    // container for the element
public:
    /*
     * self-defined exception class for pop() and top() with empty queue
    */
    class ReadEmptyQueue : public std::exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "oops, read empty queue!";
        }
    };

    // number of element
    typename std::deque<T>::size_type size() const
    {
        return c.size();
    }

    // check if queue is empty
    bool empty() const
    {
        return c.empty();
    }

    // push element into the queue
    void push(const T& elem)
    {
        c.push_back(elem);
    }

    // read element from the queue and return the value
    T pop()
    {
        if (c.empty())
            throw ReadEmptyQueue();
        T elem(c.front());
        c.pop_front();
        return elem;
    }

    // return the value of next element
    T& front()
    {
        if (c.empty())
            throw ReadEmptyQueue();
        return c.front();
    }
private:
};
