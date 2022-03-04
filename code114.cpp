#include "tree_node_util.hpp"

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        TreeNode *prev = nullptr;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            if (prev != nullptr)
                prev->right = node;

            if (node->right != nullptr)
                stk.push(node->right);
            if (node->left != nullptr)
                stk.push(node->left);
            node->left = nullptr;
            node->right = nullptr;
            prev = node;
        }
    }
};