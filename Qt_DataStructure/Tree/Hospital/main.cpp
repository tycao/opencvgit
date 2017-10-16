#pragma warning(disable:4786)

#include <fstream>
#include <sstream>
#include "part.h"

void load(char* filename)
{
    std::ifstream inf(filename);
    std::string part, subpart;
    int quantity;

    std::string text;
    while (getline(inf, text))
    {
        std::istringstream s(text);
        s >> part >> quantity >> subpart;
        add_part(part, quantity, subpart);
    }
}

void whatis(const std::string& x)
{
    Part* xp = partContainer.lookup(x);
    cout << endl;
    xp->describe();
}

void howmany(const string& x, const std::string& y)
{
    Part* xp = partContainer.lookup(x);
    Part* yp = partContainer.lookup(y);
    cout << "\n" << y << " has " << yp->count_howmany(xp) << " " << x << endl;
}

void process(char* filename)
{
    std::ifstream inf(filename);
    std::string query, x, y;

    std::string text;
    while (getline(inf, text))
    {
        std::istringstream s(text);
        s >> query >> x;
        if (query == "howmany")
            s >> y;
        if (query == "howmany")
            howmany(x, y);
        else if (query == "whatis")
            whatis(x);
        else
        {
            std::cerr << "ERROR!!!Cant not query: " << query << endl;
            return;
        }
    }
}
int main(int argc, char *argv[])
{
    load("C:\\Users\\Administrator\\Documents\\Visual\ Studio\ 2013\\Projects\\Qt_DataStructure\\Tree\\Hospital\\data\\definitions.txt");
    process("C:\\Users\\Administrator\\Documents\\Visual\ Studio\ 2013\\Projects\\Qt_DataStructure\\Tree\\Hospital\\data\\queries.txt");
    return 0;
}
