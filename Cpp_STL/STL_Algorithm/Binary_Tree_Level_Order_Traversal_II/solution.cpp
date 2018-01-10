#include "solution.h"

using namespace std;

std::vector<std::vector<int>> Solution::levelOrderBottom(TreeNode *root) {
    levelOrderBottom(root, 0);
    return vector<vector<int>>(vec_.rbegin(), vec_.rend());
}

void Solution::levelOrderBottom(TreeNode* root, int level) {
    if (root == nullptr) return;
    if (vec_.size() == level) vec_.push_back({root->val});
    else vec_[level].push_back(root->val);
    levelOrderBottom(root->left, level + 1);
    levelOrderBottom(root->right, level + 1);
}
