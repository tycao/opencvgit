#include <fstream>
#include <stack>
#include <sstream>
#include "car.h"

int main(int argc, char *argv[])
{
    string filename("../data.txt");
    ifstream in(filename);

    if (!in)
    {
        cerr << "Can't open the file" + filename << endl;
        EXIT_FAILURE;
    }
    stack<car*> parking_lot, tempStack;
    car* pcar;
    string license_plate, action;
    // 按行读取数据
    string str;
    while (getline(in, str))
    {
        if (!str.empty())
        {
            istringstream text(str);
            text >> license_plate >> action;
            cout << license_plate << "->" << action << endl;
        }
    }

    return 0;
}
