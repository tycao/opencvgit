#pragma once

#include <algorithm>


namespace std {
// ÉùÃ÷ÈİÆ÷set
template<typename T,
         typename Compare = less<T>,
         typename Allocator = allocator<T>>
class set;

// ÉùÃ÷ÈİÆ÷multiset
template<typename T,
         typename Comapre = less<T>,
         typename allocator = allocator<T>>
class multiset;
}

