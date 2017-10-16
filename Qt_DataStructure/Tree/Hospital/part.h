#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Part
{
public:
    std::string name;
    std::map<Part*, int> subparts;

    Part(const std::string & n);
    void describe(void);
    int count_howmany(const Part* p);
    int myCount(std::map<Part*, int>& myMap, const Part* p, int num);
};



class NameContainer
{
private:
    std::map<std::string, Part*> name_map;
public:
    ~NameContainer();
    NameContainer(void);
    Part* lookup(const std::string& name);
};

// ����һ��ȫ�ֺ���
void add_part(const std::string& x, int q, const std::string& y);

// �����������������ͱ���
extern NameContainer partContainer;
