#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
    /*
     * enumeration type for the bits
     * - each bit represent a color
    */
    enum Color { red, yellow, green, blue, white, black, numColor };

    // create bitset for all bits/colors
    bitset<numColor> usedColor;

    // set bits for two colors
    usedColor.set(red);
    usedColor.set(yellow);

    // print some bitset data
    cout << "bitfield of used colors: " << usedColor << endl;
    cout << "numbers of used color : " << usedColor.count() << endl;
    cout << "bitfield of unused color : " << ~usedColor << endl;

    // if any color is used
    if (usedColor.any())
    {
        // loop over all colors
        for (int c = 0; c != numColor; ++c)
            if (usedColor[static_cast<Color>(c)])
                cout << "used colors : " << static_cast<Color>(c) << endl;
    }

    return 0;
}
