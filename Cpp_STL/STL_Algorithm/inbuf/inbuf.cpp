#include "inbuf.h"


// constructor
inbuf::inbuf() {
    char buffer[buffersize] = {'0'};
    setg(buffer + 4,    // beginning of putback area
         buffer + 4,    // read position
         buffer + 4);   // end position
}

// insert new characters into the buffer
inbuf::int_type inbuf::underflow() {
    // is read position before end of buffer
    if (gptr() < egptr()) {
        return *gptr();
    }

    /*
     * process size of putback area
     * - use number of characters read
     * - but at most four
    */
    int numPutback;
    numPutback = gptr() - eback();
    if (numPutback > 4)
        numPutback = 4;

    /* copy up to 4 characters previously read,
     * - into the putback buffer(area of first four characters)
    */
    std::memcpy(buffer + (4 - numPutback), gptr() - numPutback, numPutback);    // copy

    // read new characters
    int num;
    num = read(0,   // 标准输入
               buffer + 4,  // 读取位置 read position
               buffersize - 4); // 读取数量
    if (num <= 0)
        return EOF; // error or eof

    // reset buffer pointers
    setg(buffer + (4 - numPutback), // beginning of putback area
         buffer + 4,    // read postion
         buffer + 4 + num); // end of buffer

    // return next hcaracters
    return *gptr();
}


const int inbuf::buffersize = 20;
