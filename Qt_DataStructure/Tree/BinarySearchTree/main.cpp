#include "binarysearchtreenode.h"

int main(int argc, char *argv[])
{
    BinaryNode* lt1 = new BinaryNode(1, 0, 0);
    BinaryNode* rt1 = new BinaryNode(2, 0, 0);
    BinaryNode* root = new BinaryNode(10, lt1, rt1);
    BinarySearchTree btree(root);

    btree.insert(3, root);
    btree.insert(4, root);
    btree.insert(5, root);

    btree.insert(6, lt1);
    btree.insert(7, rt1);
    btree.insert(11, rt1);

    btree.insert(12, rt1);

    if (btree.find(12, root) != nullptr)
        cout << btree.find(12, root)->GetElement() << endl;
    else
        cout << "null pointer!" << endl;

    return 0;
}
