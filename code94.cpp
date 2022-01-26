#include "tree_node_util.hpp"

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    void inorderTraversal(TreeNode *node, vector<int> &result)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left, result);
        result.push_back(node->val);
        inorderTraversal(node->right, result);
    }
};