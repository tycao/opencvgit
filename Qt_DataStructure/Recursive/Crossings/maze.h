#pragma once

#include <vector>
#include "crossings.h"


class Maze
{
private:
    int exit;   //���ڱ���
    std::vector<Crossings> crossings;   // ·�ڼ���
    std::vector<int> result;
public:
    // ���캯��
    Maze(int the_exit, vector<Crossings> the_crossings);
    int findExit(int entrance); // �Թ����
    void getResult();    // ȡ���Թ��� ����ӡ
};
