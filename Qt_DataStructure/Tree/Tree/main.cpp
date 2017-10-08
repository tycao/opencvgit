#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{
    TreeNode<int>* tNode1 = new TreeNode<int>(10);
    TreeNode<int>* tNode2 = new TreeNode<int>(11);
    TreeNode<int>* tNode3 = new TreeNode<int>(12);
    TreeNode<int>* tNode4 = new TreeNode<int>(13);
    TreeNode<int>* tNode5 = new TreeNode<int>(14);
    TreeNode<int>* tNode6 = new TreeNode<int>(15);
    TreeNode<int>* tNode7 = new TreeNode<int>(16);
    TreeNode<int>* tNode8 = new TreeNode<int>(17);
    TreeNode<int>* tNode9 = new TreeNode<int>(18);

    Tree<int> tree(tNode1);
    tree.insertChild(tNode1, tNode2);
    tree.insertChild(tNode1, tNode3);
    tree.insertChild(tNode1, tNode4);
    tree.insertChild(tNode1, tNode5);

    tree.insertChild(tNode2, tNode6);
    tree.insertChild(tNode2, tNode7);
    tree.insertChild(tNode2, tNode8);

    tree.insertChild(tNode3, tNode9);

    if (!tree.isEmpty())
    {
        cout << "tree.getRoot() : " << tree.getRoot()->getValue() << endl;
        cout << "tNode2.getRightSibling() : " << tNode2->getRightSibling()->getValue() << endl;
        cout << "tree.getNextSibling(TreeNode<T>* t) : " << tree.getNextSibling(tNode2)->getValue() << endl;
    }

    return 0;
}
