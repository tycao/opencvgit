#include <conio.h>
#include "avltree.h"

int main(int argc, char *argv[])
{
    AvlTree<int> tree;
    tree.Insert(88);
    tree.Insert(39);
    tree.Insert(36);
    tree.Insert(35);
    tree.Insert(28);
    tree.Insert(21);
    tree.Insert(15);
    tree.Insert(14);
    tree.Insert(12);
    tree.Insert(9);
    tree.Insert(7);
    tree.Insert(10);
    tree.Insert(39);
    tree.Insert(0);

/*
    tree.Insert(15);
    tree.Insert(36);
    tree.Insert(14);
    tree.Insert(7);
    tree.Insert(28);
    tree.Insert(9);
*/
    tree.DisplayTree(tree.GetRoot(), 15);

    while (true)
    {
        int number;
        std::cout << "请输入要删除的结点：" << std::endl;
        cin >> number;
        tree.Remove(number);

        std::cout << "删除以后的树是：" << std::endl;
        tree.DisplayTree(tree.GetRoot(), 0);

        std::cout << "按ESC退出，或者按任意键继续" << std::endl;
        int order = getch();
        if (order == 27)
            break;
    }
    return 0;
}
