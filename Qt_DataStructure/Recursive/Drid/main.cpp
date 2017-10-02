#include "grid.h"

//constexpr int ROWS = 6;
//constexpr int COLS = 6;
#define ROWS 6
#define COLS 6
#define TOTAl 13    // 被感染点的总数
constexpr int TOTAL = 13;
// 标记被感染点的坐标的数组
int theCity[TOTAL][2] =
{
    {0, 0},
    {1, 1},
    {2, 2},
    {2, 3},
    {2, 5},
    {3, 2},
    {3, 3},
    {3, 5},
    {4, 0},
    {4, 2},
    {4, 3},
    {4, 5},
    {5, 0},
};

int main(int argc, char *argv[])
{
    grid* g;
    int col;
    int row;
    g = new grid((int*)theCity, ROWS, COLS, TOTAL);
    cout << "please input the detect point (Format : x y) :" << endl;
    cin >> row >> col;
    cout << "The colony including the cell at "
         << "(" << row << "," << col << ")"
         << " has an area of " << g->count(row, col) << " units."
         << endl;
    cout << *g << endl;
    delete g;
    return EXIT_SUCCESS;
}
