#pragma once

#include <functional>

// class for the compose_f_gx_hy adapter
template<typename OP1, typename OP2, typename OP3>
class compose_f_gx_hy_t
        : public std::binary_function<typename OP2::argument_type,
                                     typename OP3::argument_type,
                                     typename OP1::result_type>
{
public:
    // constructor
    compose_f_gx_hy_t(const OP1& o1, const OP2& o2, const OP3& o3)
        : op1(o1), op2(o2), op3(o3)
    {

    }

    // overload function callable operator 重载 函数调用运算符
    typename OP1::result_type
    operator ()(const typename OP2::argument_type& x, const typename OP3::argument_type& y) const
    {
        return op1(op2(x), op3(y));
    }
private:
    OP1 op1;    // process : op1(op2(x), op3(x))
    OP2 op2;
    OP3 op3;
};
// convenience function for the compose_f_gx_hy adapter

template<typename OP1, typename OP2, typename OP3>
inline compose_f_gx_hy_t<OP1, OP2, OP3> compose_f_gx_hy(const OP1& o1, const OP2& o2, const OP3& o3)
{
    return compose_f_gx_hy_t<OP1, OP2, OP3>(o1, o2, o3);
}
