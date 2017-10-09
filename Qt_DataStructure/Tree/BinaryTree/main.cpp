#include "binarytree.h"

int main(int argc, char *argv[])
{
    /*
     * �������Ľṹ����ͼ��ʾ��
     *                   a
     *                 /  \
     *                B    C
     *               / \  / \
     *              D   E F  G
     *
     *
     *
    */
    BinaryTree<char> myBinTree('a');

    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'D');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'G');
    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');
    myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');
    myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');

    cout << "�ö������Ƿ�Ϊ�գ�" << boolalpha << myBinTree.IsEmpty() << endl;

    cout << "�ö������и��ڵ�洢�������ǣ�"
         << myBinTree.GetData(myBinTree.GetRoot()) << endl;

    cout << "���������и��ڵ��е����ݸ�ֵΪA!";
    myBinTree.Assign(myBinTree.GetRoot(), 'A');
    cout << "\n��ǰ�������и��ڵ�洢������Ϊ�� "
         << myBinTree.GetData(myBinTree.GetRoot()) << endl;

    cout << "��α���������£� " << endl;
    myBinTree.LevelOrderTraverse(myBinTree.GetRoot());
    cout << endl;

    cout << "ǰ�������ǰ��������������£�" << endl;
    myBinTree.PreOrderTraverse(myBinTree.GetRoot());
    cout << endl;

    cout << "����������и�������������£�" << endl;
    myBinTree.InOrderTraverse(myBinTree.GetRoot());
    cout << endl;

    cout << "������������������������£�" << endl;
    myBinTree.PostOrderTraverse(myBinTree.GetRoot());
    cout << endl;

    return 0;
}
