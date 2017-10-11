#include <cstring>
#include <cstdlib>  // �ȼ���#include <malloc.h>
#include "huffman.h"

/*
 * ���������ṹ
*/
//class HuffmanTree
//{
//public:
//    unsigned Weight, Parent, lChild, rChild;
//};
//typedef char** HuffmanCode;

/*
 * �ӽڵ㼯����ѡ��Ȩֵ��С�������ڵ�
 * ��ֵ�ֱ𸳸� s1 �� s2
*/
void Select(HuffmanTree* HT, int Count, int* s1, int* s2)
{
    unsigned temp1 = 0, temp2 = 0, temp3;
    for (int i = 1; i <= Count; ++i)
    {
        if (HT[i].Parent == 0)
        {
            if (temp1 == 0)
            {
                temp1 = HT[i].Weight;
                *s1 = i;
            }
            else
            {
                if (temp2 == 0)
                {
                    temp2 = HT[i].Weight;
                    *s2 = i;
                    if (temp2 < temp1)
                    {
                        temp3 = temp2;
                        temp2 = temp1;
                        temp1 = temp3;
                        temp3 = *s2;
                        *s2 = *s1;
                        *s1 = temp3;
                    }
                }
                else
                {
                    if (HT[i].Weight < temp1)
                    {
                        temp2 = temp1;
                        temp1 = HT[i].Weight;
                        *s2 = *s1;
                        *s1 = i;
                    }
                    if (HT[i].Weight > temp1 && HT[i].Weight < temp2)
                    {
                        temp2 = HT[i].Weight;
                        *s2 = i;
                    }
                }
            }
        }
    }
}

/*
 * ���������뺯��
*/
void HuffmanCoding ( HuffmanTree* HT,
                     HuffmanCode* HC,
                     int* Weight,
                     int Count )
{
    int i;
    int s1, s2;
    int TotalLength;
    char* cd;
    unsigned c, f;
    int start;
    if (Count <= 1) return;
    TotalLength = Count * 2 - 1;
    HT = new HuffmanTree[TotalLength + 1];

    for (i = 1; i <= Count; ++i)
    {
        HT[i].Parent = 0;
        HT[i].rChild = 0;
        HT[i].lChild = 0;
        HT[i].Weight = *Weight;
        ++Weight;
    }

    for (i = Count + 1; i <= TotalLength; ++i)
    {
        HT[i].Parent = 0;
        HT[i].lChild = 0;
        HT[i].rChild = 0;
        HT[i].Weight = 0;
    }

    // �����������
    for (i = Count + 1; i <= TotalLength; ++i)
    {
        Select(HT, i - 1, &s1, &s2);
        HT[s1].Parent = i;
        HT[s2].Parent = i;
        HT[i].lChild = s1;
        HT[i].rChild = s2;
        HT[i].Weight = HT[s1].Weight + HT[s2].Weight;
    }

    // �������������
    // ʹ��malloc��ջ������һ���ڴ棬��СΪ(Count+1)*sizeof(char*)
    *HC = static_cast<HuffmanCode>(malloc((Count + 1) * sizeof(char*)));
    cd = new char[Count * sizeof(char)];    // ʹ��new������ ���������һ���СΪCount���ֽڵ��ڴ�ռ�
    cd[Count - 1] = '\0';   // ��cd��������һ��Ԫ�ص�ֵ����Ϊ'\0' ��˵���ַ�������'\0'�ᱻ�ضϡ�

    for (i = 1; i <= Count; ++i)
    {
        start = Count - 1;
        for (c = i, f = HT[i].Parent; f != 0; c = f, f = HT[f].Parent)
        {
            if (HT[f].lChild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            (*HC)[i] = new char[ Count - start ];
            strcpy((*HC)[i], &cd[start]);
        }
    }
    delete [] HT;
    delete [] cd;
}

/*
 * ���ַ����в���ĳ���ַ�
 * ����ҵ����򷵻���λ��
*/
int LookFor(char* str, char letter, int count)
{
    int i;
    for (int i = 0; i != count; ++i)
        if (str[i] == letter)
            return i;
    return -1;
}

/*
 *
*/
void OutputWeight( char* Data,
                   int Length,
                   char** WhatLetter,
                   int** Weight,
                   int* Count )
{

}

