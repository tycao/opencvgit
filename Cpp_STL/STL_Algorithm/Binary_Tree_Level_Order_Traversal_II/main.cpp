#include <iostream>
#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    Solution s;

    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    for (auto vec : s.levelOrderBottom(&root)) {
        for (auto i : vec)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}
