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
    HT = new HuffmanTree[TotalLength + l];

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

}

#endif
