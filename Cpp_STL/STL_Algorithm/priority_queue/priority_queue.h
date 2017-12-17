#pragma once

#include <vector>   // for vector<>
#include <functional>   // for less<>

namespace std {
template<typename T, typename Container = vector<T>,
         typename Compare = less<typename Container::value_type>>
class priority_queue
{
public:
    // type alias
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type size_type;
    typedef Container container_type;

    // constructor
    explicit priority_queue(const Compare& cmp = Compare(), const Container& cont = Container())
        : comp(cmp), c(cont)
    {
        make_heap(c.begin(), c.end(), comp);
    }

    template<typename InputIterator>
    priority_queue(InputIterator first, InputIterator last,
                   const Compare& cmp = Compare(),
                   const Container& cont = Container())
        : comp(cmp), c(cont)
    {
        c.insert(c.end(), first, last);
        make_heap(c.begin(), c.end(), comp);
    }

    void push(const value_type& x)
    {
        c.push_back(x);
        push_heap(c.begin(), c.end(), comp);
    }

    void pop()
    {
        pop_heap(c.begin(), c.end(), comp);
        c.pop_back();
    }

    bool empty() const
    {
        return c.empty();
    }

    size_type size() const
    {
        return c.size();
    }

    const value_type& top() const
    {
        return c.front();
    }
protected:
    Compare comp;   // sorting criteria
    Container c;    // container of element
private:

};
}
