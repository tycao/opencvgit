#include "grid.h"

std::ostream& operator <<(ostream& os, const grid& ob)
{
    for (int row = 0; row < ob.rows; ++row)
        for (int col = 0; col != ob.cols; ++col)
        {
            os << ob.area->operator [](ob.indexof(row, col));
            if (ob.marked_area->operator [](ob.indexof(row, col)))
                os << "+ ";
            else
                os << " ";
        }
    os << endl;
    os << endl;
    return os;
}

// 构造函数
grid::grid(int* theCity, int row, int col, int total) :
    number(0),
    rows(row),
    cols(col),
    area(new vector<bool>(rows * cols, NOT_INFECTED)),     // rows * cols 的个数 ：默认未感染的。
    marked_area(new vector<bool>(rows * cols, NOT_INFECTED))
{
    for (int i = 0; i != total; ++i)
    {
        int blob_row;
        int blob_col;
        blob_row  = theCity[i * 2];
        blob_col = theCity[i * 2 + 1];
        area->operator [](indexof(blob_row, blob_col)) = INFECTED;
    }
}
grid::~grid()    // 析构函数
{
    delete area;
    delete marked_area;
}
int grid::count(int row, int col)
{
    caculate(row, col);
    return number;
}

// 私有数据成员
int grid::indexof(int row, int col) const
{
    return row * cols + col;
}
bool grid::infected(int row, int col) const
{
    return (area->operator [](indexof(row, col)) == INFECTED);
}
void grid::caculate(int row, int col)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || marked_area->operator [](indexof(row, col)))
        return;
    if (infected(row, col))
    {
        marked_area->operator [](indexof(row, col)) = INFECTED;
        ++number;
        caculate(row, col + 1);
        caculate(row, col -1);
        caculate(row + 1, col);
        caculate(row - 1, col);
        caculate(row + 1, col + 1);
        caculate(row + 1, col - 1);
        caculate(row - 1, col - 1);
        caculate(row - 1, col + 1);
    }
}
