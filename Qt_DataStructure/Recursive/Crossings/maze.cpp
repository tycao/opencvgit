#include "maze.h"

// ���캯��
Maze::Maze(int the_exit, vector<Crossings> the_crossings) : exit(the_exit), crossings(the_crossings) { }

// �Թ���� �����㷨
int Maze::findExit(int entrance)
{
    if (entrance > 0)
    {
        if (entrance == exit)
        {
            result.push_back(entrance);
            return 1;
        }
        if (findExit(crossings[entrance].turn1))
        {
            result.push_back(entrance);
            return 1;
        }
        if (findExit(crossings[entrance].turn2))
        {
            result.push_back(entrance);
            return 1;
        }
        if (findExit(crossings[entrance].turn3))
        {
            result.push_back(entrance);
            return 1;
        }
    }
    return 0;
}

// ȡ���Թ��� ����ӡ
void Maze::getResult()
{
    findExit(1);

    for (int i = result.size(); i != 0; --i)
        cout << result[i - 1] << "->";
    cout << "Exit" << endl;
}
