#pragma once

#pragma once


// type for sorting criterion
template<typename T>
class RuntimeCmp
{
public:
    enum cmp_mode
    {
        normal,
        reverse
    };

    // constructor for sorting criterion
    // - default criterion uses value normal
    RuntimeCmp(cmp_mode m = normal)
        : mode(m)
    {

    }

    // comparison of elements
    bool operator ()(const T& t1, const T& t2) const
    {
        return mode == normal ? t1 < t2 : t2 < t1;
    }

    // comparison of sorting criterion
    bool operator == (const RuntimeCmp& rc)
    {
        return mode == rc.mode;
    }
private:
    cmp_mode mode;
};

