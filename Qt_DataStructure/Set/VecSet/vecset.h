#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class VecSet
{
    friend std::ostream& operator << (std::ostream& os, VecSet& vset);
public:
    VecSet();   // Ĭ�Ϲ��캯��
    VecSet(int MaxSize);    // ����һ��int�����βεĹ��캯��

    // public member function
    void Add(int add);
    void Del(int del);
    void MakeEmpty();
    int GetSize();
    int GetAt(int index);
    VecSet& operator + (VecSet& another);   // �����'+'����
    VecSet& operator - (VecSet& another);   // �����'-'����
    VecSet& operator * (VecSet& another);   // �����'*'����
    VecSet& operator = (VecSet& another);   // �����'='����
    bool operator == (VecSet& another);  // �����'=='����
private:
    void checkSize(VecSet& another);
    int* contain;
    int size;
};
// ȫ�ֺ���
inline std::ostream& operator << (std::ostream& os, VecSet& vset)
{
    for (int i = 0; i != vset.GetSize(); ++i)
        cout << vset.GetAt(i) << "*";   //���λ��������ļ���
    return os;
}
