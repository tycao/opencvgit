#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <streambuf>    // for basic_streambuf<char, traits>
#include <locale>   // for getloc()
#include <cstdio>   // for std::toupper()


template<typename charT, typename traits = std::char_traits<charT>>
class basic_outbuf : public std::basic_streambuf<charT, traits> {
protected:
    /*
     * central output function
     * - print characters in uppercase mode
    */
    virtual typename traits::int_type overflow(typename traits::int_type c);
};

template<typename charT, typename traits>
typename traits::int_type basic_outbuf<charT, traits>::overflow(typename traits::int_type c)  {
    if (!traits::eq_int_type(c, traits::eof())) {
        // convert lowercase to uppercase
        c = std::toupper(c, std::streambuf::getloc());

        // write the character to the standard output
        if (putchar(c) == EOF) {
            return traits::eof();
        }
    }
    return traits::not_eof(c);
}

typedef basic_outbuf<char> outbuf;
typedef basic_outbuf<wchar_t> woutbuf;
