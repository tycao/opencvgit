#pragma once

#include <iostream>


namespace std {
/*
 * general numeric limits as default for any type
 * 原始模版
*/
template<typename T>
class numeric_limits
{
public:
    // no specialization for numeric limits exist
    // ************************* const (常量) 数据成员 可以在类内初始化*******************************************
    static const bool is_specialized = false;

    // ...other members that are meaningless for the general numeric limits
    /* NULL */
};

/*
 * 模版全特化
 * numeric limits for int
 * - implementation defined
*/
template<>
class numeric_limits<int>
{
public:
    // yes, a specialization for numeric limits of int does exist
    // ************************* const (常量) 数据成员 可以在类内初始化*******************************************
    static const bool is_specialized{true};

    inline static int min() noexcept
    {
        return -2147483648;
    }
    inline static int max() noexcept
    {
        return 2147483648;
    }

    // ************************* const (常量) 数据成员 可以在类内初始化*******************************************
    static const int digits = 31;
};
/*
template<>
int numeric_limits<int>::digits = 31;

template<>
bool numeric_limits<int>::is_specialized = true;
*/




/*
 * 模版全特化
 * numeric limits for float
*/
template<>
class numeric_limits<float>
{
public:
    // yes, a specialization for numeric limits of float does exist
    static const bool is_specialized = true;

    inline static float min() noexcept
    {
        return 1.17549435e+38F;
    }
    inline static float max() noexcept
    {
        return 3.40282347E+38F;
    }

    static constexpr int digits{ 24 };
    static constexpr int digits10{ 6 };

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;
    static constexpr bool is_iec559 = true;

    static constexpr int radix = 2;
    inline static float epsilon() noexcept
    {
        return 1.19209290E-07F;
    }

    //static const float_round_style round_style = round_to_nearest;
    inline static float round_error() noexcept
    {
        return 0.5f;
    }

    // ************************* const (常量) 数据成员 可以在类内初始化***********************************
    static const int min_exponent = -125;
    static const int max_exponent = +128;
    static const int min_exponent10 = -37;
    static const int max_exponent10 = +38;

    static constexpr bool has_infinity = true;
    inline static float infinity() noexcept { return 1.1111191; }
    static constexpr bool has_quiet_NaN{ true };

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = true;
};
}
