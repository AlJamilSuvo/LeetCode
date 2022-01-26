#include "tree_node_util.hpp"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
            return false;

        if (left->val != right->val)
            return false;

        if (!isSymmetric(left->right, right->left))
            return false;

        if (!isSymmetric(left->left, right->right))
            return false;

        return true;
    }
};


