#include <iostream>
#include <iterator>

int main(int argc, char *argv[])
{
    // create istream iterator that reads integers from standard input
    std::istream_iterator<int> intRead(std::cin);

    // create end-of-stream iterator
    std::istream_iterator<int> intReadEOF;  // end-of-stream iterator is actually created by default constructor

    // while able to read tokens with istream iterator
    // - write them twice
    while (intRead != intReadEOF)
    {
        std::cout << "once : " << *intRead << "\n";
        std::cout << "twice : " << *intRead << "\n";
        ++intRead;
    }

    return 0;
}
