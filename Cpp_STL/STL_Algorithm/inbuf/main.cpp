#include <iostream>
#include "inbuf.h"

int main(int argc, char *argv[])
{
    inbuf ib;   // 创建一个特殊的流缓冲区
    std::istream in(&ib);   // 用刚刚创建的流缓冲区 初始化input流（读取流 或 输入流）

    char c;
    for (int i = 1; i <= 20; ++i) {
        // 读取下一个字符（缓冲区之外）
        in.get(c);

        // 打印刚刚读取的字符（且通过flush,清空缓冲区）
        std::cout << c << std::flush;

        // 8个字符之后，将2个字符插回到流内
        if (i == 8) {
            in.unget();
            in.unget();
        }
    }

    std::cout << "\n";
    return 0;
}
