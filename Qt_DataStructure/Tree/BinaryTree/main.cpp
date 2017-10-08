#include "binarytree.h"

int main(int argc, char *argv[])
{
    BinaryTree<char> myBinTree('a');

    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'D');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'G');
    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');
    myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');
    myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');

    cout << "该二叉树是否为空？" << boolalpha << myBinTree.IsEmpty() << endl;

    cout << "该二叉树中根节点存储的数据是："
         << myBinTree.GetData(myBinTree.GetRoot()) << endl;

    cout << "将二叉树中根节点中的数据赋值为A!";
    myBinTree.Assign(myBinTree.GetRoot(), 'A');
    cout << "\n当前二叉树中根节点存储的数据为： "
         << myBinTree.GetData(myBinTree.GetRoot()) << endl;

    cout << "层次遍历结果如下： " << endl;
    myBinTree.LevelOrderTraverse(myBinTree.GetRoot());
    cout << endl;

    return 0;
}
