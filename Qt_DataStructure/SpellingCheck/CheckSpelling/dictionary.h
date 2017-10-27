#pragma once

#include <list>
#include <string>
#include <cstdlib>
#include <fstream>

#include "hashset.h"

using namespace std;

// �����˺���������������ࣨ���������ࣩ
class hash_function
{
public:
    hash_function();  // Ĭ�Ϲ��캯��
    unsigned int operator ()(const std::string& s) const;   // ���غ����������������������������
};

// �����˺���������������ࣨ���������ࣩ
class equality
{
public:
    equality(); // Ĭ�Ϲ��캯��
    bool operator ()(const std::string& A, const std::string& B) const; // ���غ����������������������������
};


class Dictionary : public HashSet<std::string, hash_function, equality>
{
protected:
    std::ifstream infile;
public:
    Dictionary(const std::string& filename);    // ���캯��
};
