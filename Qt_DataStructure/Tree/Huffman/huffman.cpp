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
    char* Letter = new char[Length];
    int* LetterCount = new int[Length];
    int i, AllCount = 0, index, Sum = 0;
    float Persent = 0;
    for (i = 0; i != Length; ++i)
    {
        if (i == 0)
        {
            Letter[0] = Data[i];
            LetterCount[0] = 1;
            ++AllCount;
        }
        else
        {
            index = LookFor(Letter, Data[i], AllCount);
            if (index == -1)
            {
                Letter[AllCount] = Data[i];
                LetterCount[AllCount] = 1;
                ++AllCount;
            }
            else ++LetterCount[index];
        }
    }

    for (i = 0; i != AllCount; ++i)
        Sum = Sum + LetterCount[i];

    *Weight = new int[AllCount];
    *WhatLetter = new char[AllCount];
    for (i = 0; i != AllCount; ++i)
    {
        Persent = static_cast<float>(LetterCount[i]) / static_cast<float>(Sum);
        (*Weight)[i] = (int) (1000 * Persent);
        (*WhatLetter)[i] = Letter[i];
    }
    *Count = AllCount;
    delete [] Letter;
    delete [] LetterCount;
}

