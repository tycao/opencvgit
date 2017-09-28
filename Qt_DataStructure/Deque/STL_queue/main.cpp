/*
 * 游程编码问题（Run Length Coding）：
 * 游程编码是一种相对简单的无损压缩编码技术。它在早期的图片压缩中被广泛使用,PCX就是一种使用游程编码方式的图像格式。它的原理很简单：
 * 即时基于图像的统计特性基础，将一个相同值的连续串用一个代表值和一个串长来代替。如黑白像素点连续出现的像素点数 称为“游程长度”，简称“长度”。
 * 该方法更适合于 *二值图像* 或 *黑白图像* 的编码压缩。
*/
#include <queue>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int> picture;
    char a;
    float pow = 0;
    float oriSize;
    cout << "please input 01 sequence(ending with #):";
    do
    {
        cin >> a;
        if (a != '#')
            picture.push(a);
    } while (a != '#');
    int size = picture.size();
    oriSize = size;
    char pic = picture.front();
    picture.pop();
    cout << "After Coding: ";
    while (!picture.empty())
        if (pic == picture.front())
        {
            pic = picture.front();
            picture.pop();
        }
        else
        {
            cout << size - picture.size();
            pow++;
            size = picture.size();
            pic = picture.front();
            picture.pop();
        }
    cout << size << endl;
    pow++;
    cout << "Compress Rate: " << pow / oriSize << endl;

    return 0;
}
