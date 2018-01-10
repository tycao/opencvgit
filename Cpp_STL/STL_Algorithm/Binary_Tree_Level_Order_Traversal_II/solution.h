#pragma once

#include <vector>
#include "treenode.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *);
private:
    void levelOrderBottom(TreeNode*, int);
    std::vector<std::vector<int>> vec_;
};
