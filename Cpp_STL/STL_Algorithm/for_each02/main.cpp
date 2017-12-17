#include "meanvalue.h"
#include "../../../print.h"

int main(int argc, char *argv[])
{
    std::vector<int> coll;

    INSERT_ELEMENT(coll, 1, 8);

    // process and print mean value
    double mv = std::for_each(coll.begin(), coll.end(),     // source range
                              MeanValue());    // operation

    // print mv
    std::cout << "mean value : " << mv << std::endl;

    return 0;
}
