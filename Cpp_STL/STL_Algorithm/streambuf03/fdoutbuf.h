#pragma once

#include <iostream>
#include <streambuf>
#include <cstdio>
#include <iterator>
#include <fstream>

typedef ptrdiff_t	streamsize;
extern "C" int write(int fd, const char* buf, int num);

class fdoutbuf : public std::streambuf {
public:
    fdoutbuf(int _fd) : fd(_fd) {}
protected:
    virtual int_type overflow(int_type c){
        if (c != EOF) {
            char z = c;
            if (write(fd, &z, 1)) {
                return EOF;
            }
        }
        return c;
    }

    virtual std::streamsize xsputn(const char_type *__s, streamsize __n){
        return write(fd, __s, __n);
    }
    // data member
    int fd;
};

