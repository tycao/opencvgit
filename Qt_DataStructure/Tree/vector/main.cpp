#include "tree.h"
/*
 *                       0
 *                   /       \
 *                  1         2
 *                / | \    / | | \
 *               3  4  5   6 7 8 9
 *
 *
*/

int main(int argc, char *argv[])
{
    TreeNode treenode0(0);
    TreeNode treenode1(1);
    TreeNode treenode2(2);
    TreeNode treenode3(3);
    TreeNode treenode4(4);
    TreeNode treenode5(5);
    TreeNode treenode6(6);
    TreeNode treenode7(7);
    TreeNode treenode8(8);
    TreeNode treenode9(9);

    std::vector<TreeNode*> subOfTreeNode0, subOfTreeNode1, subOfTreeNode2;

    subOfTreeNode0.push_back(&treenode1);
    subOfTreeNode0.push_back(&treenode2);

    subOfTreeNode1.push_back(&treenode3);
    subOfTreeNode1.push_back(&treenode4);
    subOfTreeNode1.push_back(&treenode5);

    subOfTreeNode2.push_back(&treenode6);
    subOfTreeNode2.push_back(&treenode7);
    subOfTreeNode2.push_back(&treenode8);
    subOfTreeNode2.push_back(&treenode9);

    treenode0.setSub(&subOfTreeNode0);
    treenode1.setSub(&subOfTreeNode1);
    treenode2.setSub(&subOfTreeNode2);

    Tree tree(&treenode0);
    tree.DisplayTree(&treenode0);

    return 0;
}
