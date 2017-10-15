#include "tree.h"

Tree::Tree(TreeNode* rt) // 构造函数 ： 初始化树的根节点
    : root(rt)
{

}
void Tree::DisplayTree(TreeNode* r)
{
    cout << r->getNum() << endl;
    if (r->getSub() == nullptr)
    {
        cout << "该节点是叶子节点！" << "\n\n";
        return;
    }
    cout << "该节点的子节点是：";
    for (int i = 0; i != r->getSub()->size(); ++i)
    {
        cout << r->getSub()->at(i)->getNum() << " ";
    }
    cout << "\n\n";

    for (int i = 0; i != r->getSub()->size(); ++i)
    {
        // 使用递归获取树的整个节点
        DisplayTree(r->getSub()->at(i));
    }
}
