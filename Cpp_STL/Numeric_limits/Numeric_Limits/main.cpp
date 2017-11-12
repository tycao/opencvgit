#include "numeric_limit_float.h"

int main(int argc, char *argv[])
{
    std::numeric_limits<int> ni;
    std::cout << ni.max() << std::endl;
    std::cout << ni.min() << std::endl;
    std::cout << ni.digits << std::endl;
    std::cout << std::boolalpha << std::numeric_limits<int>::is_specialized << std::endl;

    std::numeric_limits<float> nf;
    std::cout << std::numeric_limits<float>::round_error() << std::endl;
    std::cout << nf.max() << std::endl;
    std::cout << nf.min() << std::endl;
    std::cout << std::boolalpha << std::numeric_limits<float>::has_infinity << std::endl;
    std::cout << std::numeric_limits<float>::has_quiet_NaN << std::endl;
    std::cout << std::numeric_limits<float>::traps << std::endl;
    std::cout << std::numeric_limits<float>::tinyness_before << std::endl;

    return 0;
}
