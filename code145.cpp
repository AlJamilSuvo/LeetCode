#include "tree_node_util.hpp"

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorderTraversal(root,result);
        return result;
    }

    void postorderTraversal(TreeNode *node, vector<int>& result)
    {
        if (node == nullptr)
            return;
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->val);
    }
};