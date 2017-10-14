#include "huffman.h"

/*
 * 霍夫曼树结构
*/
//class HuffmanTree
//{
//public:
//    unsigned Weight, Parent, lChild, rChild;
//};
//typedef char** HuffmanCode;

/*
 * 从节点集合中选出权值最小的两个节点
 * 将值分别赋给 s1 和 s2
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
 * 霍夫曼编码函数
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

    // 建造霍夫曼树
    for (i = Count + 1; i <= TotalLength; ++i)
    {
        Select(HT, i - 1, &s1, &s2);
        HT[s1].Parent = i;
        HT[s2].Parent = i;
        HT[i].lChild = s1;
        HT[i].rChild = s2;
        HT[i].Weight = HT[s1].Weight + HT[s2].Weight;
    }

    // 输出霍夫曼编码
    // 使用malloc向栈里申请一块内存，大小为(Count+1)*sizeof(char*)
    *HC = static_cast<HuffmanCode>(malloc((Count + 1) * sizeof(char*)));
    cd = new char[Count * sizeof(char)];    // 使用new操作符 向堆里申请一块大小为Count个字节的内存空间
    cd[Count - 1] = '\0';   // 将cd数组的最后一个元素的值设置为'\0' ：说明字符流遇到'\0'会被截断。

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
 * 在字符串中查找某个字符
 * 如果找到，则返回其位置
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

