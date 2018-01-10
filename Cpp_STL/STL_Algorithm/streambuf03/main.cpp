#include "fdostream.h"
#include "fdoutbuf.h"

int main(int argc, char *argv[])
{

    fdostream out(1);
    out << "31 hexadecimal : " << std::hex << 31 << "\n";
    return 0;
}
