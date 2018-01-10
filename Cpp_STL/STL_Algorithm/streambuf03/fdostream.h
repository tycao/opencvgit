#pragma once

#include "fdoutbuf.h"

class fdostream : public std::ostream {
protected:
    fdoutbuf buf;

public:
    fdostream (int fd) : std::ostream(0), buf(fd){
        rdbuf(&buf);
    }
};
