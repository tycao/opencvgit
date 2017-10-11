#if !defined(_HUFFMAN_H_)
#define _HUFFMAN_H_

/*
 * 霍夫曼树结构
*/
class HuffmanTree
{
public:
    unsigned Weight, Parent, lChild, rChild;
};
typedef char** HuffmanCode;

/*
 * 从节点集合中选出权值最小的两个节点
 * 将值分别赋给 s1 和 s2
*/
void Select(HuffmanTree* HT, int Count, int* s1, int* s2);

/*
 * 霍夫曼编码函数
*/
void HuffmanCoding ( HuffmanTree* HT,
                     HuffmanCode* HC,
                     int* Weight,
                     int Count );

/*
 * 在字符串中查找某个字符
 * 如果找到，则返回其位置
*/
int LookFor(char* str, char letter, int count);

/*
 *
*/
void OutputWeight( char* Data,
                   int Length,
                   char** WhatLetter,
                   int** Weight,
                   int* Count );

#endif
