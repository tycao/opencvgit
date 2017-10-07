#include "board.h"

int main(int argc, char *argv[])
{
    int x, y;
    cout << "Please input the start point (x, y)."
         << endl << "x =";
    cin >> x;
    cout << "y = ";
    cin >> y;

    ofstream out("d:\\board.txt");
    Board board(x, y);
    board.GetPath(out);

    return 0;
}
