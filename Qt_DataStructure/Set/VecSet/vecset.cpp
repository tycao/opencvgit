#include "vecset.h"

// Ĭ�Ϲ��캯��
VecSet::VecSet()
    : contain(nullptr), size(0)
{

}
// ����һ��int�����βεĹ��캯��
VecSet::VecSet(int MaxSize)
    : size(MaxSize)
{
    assert(MaxSize > 0);    // �ж�MaxSize�Ƿ�Ϸ�
    contain = new int[size];    // ����λ����
    for (int i = 0; i != size; ++i)
        contain[i] = 0;     // λ��������ֵ��Ĭ��Ϊ��
}

// public member function
void VecSet::Add(int add)
{
    assert(add >= 0 && add < size);  // �ж�add�Ƿ�Ϸ�
    contain[add] = 1;   // �����Ԫ��
}
void VecSet::Del(int del)
{
    assert(del >= 0 && del < size); // �ж�del�Ƿ�Ϸ�
    contain[del] = 0;   // ɾ��Ԫ��
}
void VecSet::MakeEmpty()
{
    for (int i = 0; i != size; ++i)
        contain[i] = 0; // ѭ��ɾ����ֱ��λ����Ϊ��
}
int VecSet::GetSize()
{
    return this->size;
}
int VecSet::GetAt(int index)
{
    assert(index >= 0 && index < size);  // �ж�index�Ƿ�Ϸ�
    if (contain[index] == 1)    // ��λ�����д�������Ϊindex��Ԫ��
        return index;           // �򷵻����Ԫ��
    else
        return -1;              // ���򷵻�-1
}

// ���������
VecSet& VecSet::operator + (VecSet& another)   // �����'+'����
{
    checkSize(another);   // �����ж����������Ƿ�ȴ�
    for (int i = 0; i != size; ++i)
        contain[i] = contain[i] || another.contain[i];  // ���� ���� ����ʵ�ּ��ϵ� ������
    return *this;
}
VecSet& VecSet::operator - (VecSet& another)   // �����'-'����
{
    checkSize(another);   // �����ж����������Ƿ�ȴ�
    for (int i = 0; i != size; ++i)
        contain[i] = this->contain[i] && (!another.contain[i]);     // ���� ����� ���㼰 ��&&�� ����ֵ˳���󼯺ϼ�Ĳ�
    return *this;
}
VecSet& VecSet::operator * (VecSet& another)   // �����'*'����
{
    checkSize(another);   // �����ж����������Ƿ�ȴ�
    for (int i = 0; i != size; ++i)
        contain[i] = contain[i] && another.contain[i];  // ���� ���롱 ������ʵ�ּ��ϵĽ���
    return *this;
}
VecSet& VecSet::operator = (VecSet& another)   // �����'='����
{
    checkSize(another);   // �����ж����������Ƿ�ȴ�
    for (int i = 0; i != size; ++i)
        this->contain[i] = another.contain[i];  // ѭ����ֵ
    return *this;
}
bool VecSet::operator == (VecSet& another)  // �����'=='����
{
    checkSize(another);   // �����ж����������Ƿ�ȴ�
    for (int i = 0; i != size; ++i)
        if (contain[i] != another.contain[i])
            return false;   // ����һ��Ԫ�ز��ȣ��򷵻�false
    return true;
}

// private member function
void VecSet::checkSize(VecSet &another)
{
    assert(this->GetSize() == another.GetSize());
}
