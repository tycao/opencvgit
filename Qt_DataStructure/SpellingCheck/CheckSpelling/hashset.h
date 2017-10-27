#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename key_type, typename hash_func, typename key_equal>
class HashSet
{
protected:
    struct Entry
    {
        Entry();    // 默认构造函数
        key_type key;
        bool used;
    };
    int entries;
    int prime;
    std::vector<Entry>* ht;
    hash_func hf;
    key_equal eq;
    int table_size() const;
    float load_factor() const;
    int resize();
public:
    HashSet();  // 默认构造函数
    virtual ~HashSet(); // 虚函数 ： 析构函数
    virtual int size() const;
    virtual bool search(const key_type& k);
    virtual void insert(const key_type& k);
    virtual void remove(const key_type& k);
};

static const int num_primes = 25;
static const unsigned long prime_list[] =
{
    53, 97, 193, 389, 769, 1543
};
// 成员函数的实现
template<typename key_type, typename hash_func, typename key_equal>
HashSet<key_type, hash_func, key_equal>::Entry::Entry() { }

template<typename key_type, typename hash_func, typename key_equal>
int HashSet<key_type, hash_func, key_equal>::table_size() const
{
    return prime_list[prime];
}

template<typename key_type, typename hash_func, typename key_equal>
float HashSet<key_type, hash_func, key_equal>::load_factor() const
{
    return float(size()) / table_size();
}

template<typename key_type, typename hash_func, typename key_equal>
int HashSet<key_type, hash_func, key_equal>::resize()
{
    if (prime == num_primes - 1)
    {
        cerr << "maximal table size reached, aborting..." << endl;
        return 2;   // exit(2)
    }
    int mm = prime_list[prime];
    ++prime;
    int m = prime_list[prime];
    std::vector<Entry>* ptr = new std::vector<Entry>(m);
    for (int i = 0; i < mm; ++i)
    {
        if ((*ht)[i].used)
        {
            key_type kk = (*ht)[i].key;
            int p = hf(kk) % m;
            while (p < m && (*ptr)[p].used)
                ++p;
            if (p == m)
                p = 0;
            while ((*ptr)[p].used)
                ++p;
            (*ptr)[p].key = kk;
            (*ptr)[p].used = true;
        }
    }
    delete ht;
    ht = ptr;
    return m;
}


template<typename key_type, typename hash_func, typename key_equal>
HashSet<key_type, hash_func, key_equal>::HashSet()  // 默认构造函数
    : entries(0),
      prime(0),
      ht(new std::vector<Entry>(prime_list[0]))
{

}
template<typename key_type, typename hash_func, typename key_equal>
HashSet<key_type, hash_func, key_equal>::~HashSet() // 虚函数 ： 析构函数
{
    delete ht;
}
template<typename key_type, typename hash_func, typename key_equal>
int HashSet<key_type, hash_func, key_equal>::size() const
{
    return entries;
}

template<typename key_type, typename hash_func, typename key_equal>
bool HashSet<key_type, hash_func, key_equal>::search(const key_type& k)
{

}

template<typename key_type, typename hash_func, typename key_equal>
void HashSet<key_type, hash_func, key_equal>::insert(const key_type& k)
{

}

template<typename key_type, typename hash_func, typename key_equal>
void HashSet<key_type, hash_func, key_equal>::remove(const key_type& k)
{

}




