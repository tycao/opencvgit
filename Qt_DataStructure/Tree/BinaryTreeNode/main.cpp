#include "binarytreenode.h"

int main(int argc, char *argv[])
{
/*
 *                    1
 *                  /  \
 *                 2    3
 *                / \   / \
 *              4    5  6  7
 *             / \   /
 *            8   9 10
 *
 *
*/
    BinaryTreeNode<int>* binaryTreeNode = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* binaryTreeNode2 = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int>* binaryTreeNode3 = new BinaryTreeNode<int>(14);
    BinaryTreeNode<int>* binaryTreeNode4 = new BinaryTreeNode<int>(16);
    BinaryTreeNode<int>* binaryTreeNode5 = new BinaryTreeNode<int>(18);
    BinaryTreeNode<int>* binaryTreeNode6 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* binaryTreeNode7 = new BinaryTreeNode<int>(11);
    BinaryTreeNode<int>* binaryTreeNode8 = new BinaryTreeNode<int>(13);
    BinaryTreeNode<int>* binaryTreeNode9 = new BinaryTreeNode<int>(15);
    BinaryTreeNode<int>* binaryTreeNode10 = new BinaryTreeNode<int>(17);

    binaryTreeNode->SetLeftChild(binaryTreeNode2);
    binaryTreeNode->SetRightChild(binaryTreeNode3);

    binaryTreeNode2->SetLeftChild(binaryTreeNode4);
    binaryTreeNode2->SetRightChild(binaryTreeNode5);

    binaryTreeNode3->SetLeftChild(binaryTreeNode6);
    binaryTreeNode3->SetRightChild(binaryTreeNode7);

    binaryTreeNode4->SetLeftChild(binaryTreeNode8);
    binaryTreeNode4->SetRightChild(binaryTreeNode9);

    binaryTreeNode5->SetLeftChild(binaryTreeNode10);

    cout << "binaryTreeNode->GetData() : " << binaryTreeNode->GetData() << endl;
    cout << "binaryTreeNode2->GetData() : " << binaryTreeNode2->GetData() << endl;
    cout << "binaryTreeNode3->GetData() : " << binaryTreeNode3->GetData() << endl;
    cout << "binaryTreeNode4->GetData() : " << binaryTreeNode4->GetData() << endl;
    cout << "binaryTreeNode5->GetData() : " << binaryTreeNode5->GetData() << endl;
    cout << "binaryTreeNode6->GetData() : " << binaryTreeNode6->GetData() << endl;
    cout << "binaryTreeNode7->GetData() : " << binaryTreeNode7->GetData() << endl;
    cout << "binaryTreeNode8->GetData() : " << binaryTreeNode8->GetData() << endl;
    cout << "binaryTreeNode9->GetData() : " << binaryTreeNode9->GetData() << endl;
    cout << "binaryTreeNode10->GetData() : " << binaryTreeNode10->GetData() << endl;

    cout << binaryTreeNode->GetLeftChild()->GetData() << endl;
    cout << binaryTreeNode->GetRightChild()->GetData() << endl;

    return 0;
}
