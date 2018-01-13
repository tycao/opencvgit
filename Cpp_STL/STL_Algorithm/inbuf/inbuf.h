#pragma once

#include <cstdio>
#include <cstring>
#include <streambuf>

extern "C" {
int read(int fd, char* buf, int num);
}

class inbuf : public std::streambuf {
protected:
    /*
     * data buffer:
     * - at most, four characters in putback area plus
     * - at most, six characters in ordinary read buffer
    */
    static const int buffersize;  // data buffer size
    char buffer[];    // data buffer

public:
    /* constructor
     * - initialize empty data buffer
     * - no putback area
     * => force underflow()
    */
    inbuf();
protected:
    // insert new characters into the buffer
    virtual int_type underflow();
};


