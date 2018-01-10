#pragma once

#include <iostream>
#include <streambuf>
#include <locale>
#include <cstdio>

class outbuf : public std::streambuf {
public:

protected:
    /*
     * central output function
     * - print characters in uppercase mode
    */
    virtual int_type overflow (int_type c);
};
