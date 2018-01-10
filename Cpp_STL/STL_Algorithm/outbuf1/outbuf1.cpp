#include "outbuf1.h"

std::streambuf::int_type outbuf::overflow (int_type c) {
    if (c != EOF) {
        // convert lowercase to uppercase
        c = std::toupper(c, getloc());

        // and write the character to the standard output
        if (putchar(c) == EOF) {
            return EOF;
        }
    }
    return c;
}
