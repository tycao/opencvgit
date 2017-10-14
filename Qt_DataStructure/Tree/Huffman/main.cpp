#include <iostream>
#include "huffman.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Unit Test
    HuffmanTree* HT = nullptr;
    HuffmanCode HC;

    char Data[100], *WhatLetter;
    int *Weight, Count;

    cout << "������һ���ı����ݣ�" << endl;
    cin >> Data;

    cout << endl;
    OutputWeight(Data, sizeof(Data) / sizeof(Data[0]), &WhatLetter, &Weight, &Count);
    HuffmanCoding(HT, &HC, Weight, Count);

    cout << "�ַ� ����Ƶ�� ������" << endl;
    for ( int i = 0; i != Count; ++i)
    {
        cout << WhatLetter[i] << "\t"
             << Weight[i] / 1000.0 << "%\t"
             << HC[i + 1]
             << endl;
    }
    cout << endl;


    return 0;
}
