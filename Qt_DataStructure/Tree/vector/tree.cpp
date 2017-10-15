#include "tree.h"

Tree::Tree(TreeNode* rt) // ���캯�� �� ��ʼ�����ĸ��ڵ�
    : root(rt)
{

}
void Tree::DisplayTree(TreeNode* r)
{
    cout << r->getNum() << endl;
    if (r->getSub() == nullptr)
    {
        cout << "�ýڵ���Ҷ�ӽڵ㣡" << "\n\n";
        return;
    }
    cout << "�ýڵ���ӽڵ��ǣ�";
    for (int i = 0; i != r->getSub()->size(); ++i)
    {
        cout << r->getSub()->at(i)->getNum() << " ";
    }
    cout << "\n\n";

    for (int i = 0; i != r->getSub()->size(); ++i)
    {
        // ʹ�õݹ��ȡ���������ڵ�
        DisplayTree(r->getSub()->at(i));
    }
}
