#include <algorithm>
#include "maze.h"

int main(int argc, char *argv[])
{
    // 创建一个迷宫，9个路口，出口为10
    Crossings c1(2, 0, 0);
    Crossings c2(4, 0, 0);
    Crossings c3(0, 0, 0);
    Crossings c4(3, 5, 0);
    Crossings c5(6, 0, 0);
    Crossings c6(7, 0, 0);
    Crossings c7(8, 9, 0);
    Crossings c8(0, 0, 0);
    Crossings c9(10, 0, 0);
    Crossings c0(0, 0, 0);

    vector<Crossings> crossings;
    crossings.push_back(c0);
    crossings.push_back(c1);
    crossings.push_back(c2);
    crossings.push_back(c3);
    crossings.push_back(c4);
    crossings.push_back(c5);
    crossings.push_back(c6);
    crossings.push_back(c7);
    crossings.push_back(c8);
    crossings.push_back(c9);


    Maze newMaze(6, crossings);
    newMaze.getResult();

    return 0;
}
