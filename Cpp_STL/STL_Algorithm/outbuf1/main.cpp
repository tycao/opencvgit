//#include "outbuf1.h"
#include "outbuf2.h"

int main(int argc, char *argv[])
{
    outbuf ob;  // create a special output stram buffer
    std::ostream out(&ob);  //  initialize the output stream with that output buffer

    out << "31 hexdecimal : " << std::hex << 31 << "\n";

    return 0;
}
