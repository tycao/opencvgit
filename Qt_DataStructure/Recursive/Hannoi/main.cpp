/*
 * 汉诺塔问题
 * 汉诺塔是一个古典的数学问题。他是一个递归方法解决的典型例子。问题如下：
 * 有一个梵塔，塔内有三个座A B C，开始时A座上有64个盘子，盘子大小相等，大的在下，小的在上。有一位老和尚，想把这64个盘子，从A座移动到C座，
 * 但每次只允许移动一个盘，且在移动的过程中，3个座上都始终保持大盘在下，小盘在上。
*/

#include <iostream>
#include <fstream>

using namespace std;

// 定义宏：盘子的数目
#define numberOfDisk 15

ofstream out("d:\\out.txt");

void Move(int n, char x, char y)
{
    out << "move " << n << " from " << x << " to " << y << endl;
}
// 递归求解
void Hannoi(int n, char a, char b, char c)
{
    if (n == 1)
        Move(1, a, c);
    else
    {
        Hannoi(n - 1, a, c, b);
        Move(n, a, c);
        Hannoi(n - 1, b, a, c);
    }
}

int main(int argc, char *argv[])
{
    out << "The solution for Hannoi, when the number of disks is "
        << numberOfDisk << endl;
    Hannoi(numberOfDisk, 'a', 'b', 'c');
    out.close();
    cout << "The End! Please Check out.txt." << endl;
    return 0;
}
