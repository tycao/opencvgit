#if !defined(_HUFFMAN_H_)
#define _HUFFMAN_H_

#include <cstring>
#include <cstdlib>  // �ȼ���#include <malloc.h>

/*
 * ���������ṹ
*/
class HuffmanTree
{
public:
    unsigned Weight, Parent, lChild, rChild;
};
typedef char** HuffmanCode;

/*
 * �ӽڵ㼯����ѡ��Ȩֵ��С�������ڵ�
 * ��ֵ�ֱ𸳸� s1 �� s2
*/
extern void Select(HuffmanTree* HT, int Count, int* s1, int* s2);

/*
 * ���������뺯��
*/
extern void HuffmanCoding ( HuffmanTree* HT,
                     HuffmanCode* HC,
                     int* Weight,
                     int Count );

/*
 * ���ַ����в���ĳ���ַ�
 * ����ҵ����򷵻���λ��
*/
extern int LookFor(char* str, char letter, int count);

/*
 *
*/
extern void OutputWeight( char* Data,
                   int Length,
                   char** WhatLetter,
                   int** Weight,
                   int* Count );

#endif
