#pragma once

#include <functional>

//class for compose_f_gx adapter

template<typename OP1, typename OP2>
class compose_f_gx_t
        : public std::unary_function<typename OP2::result_type, typename OP1::result_type>
{
public:
    // constructor
    compose_f_gx_t(const OP1& op1, const OP2& op2)
        : op1(op1),
          op2(op2)
    {

    }

    // overload function callable operator
    typename OP1::result_type
    operator()(const typename OP2::result_type& x) const
    {
        return op1(op2(x));
    }

private:
    OP1 op1;    // process : op1(op2(x))
    OP2 op2;
};

// convenience functions for the compose_f_gx adapter
template<typename OP1, typename OP2>
inline compose_f_gx_t<OP1, OP2> compose_f_gx(const OP1& o1, const OP2& o2)
{
    return compose_f_gx_t<OP1, OP2>(o1, o2);
}
