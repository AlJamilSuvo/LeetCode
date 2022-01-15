#include "tree_node_util.hpp"
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        TreeNode *current = root;
        TreeNode *parent = root;
        while (current != nullptr)
        {
            parent = current;
            if (val <= current->val)
                current = current->left;
            else
                current = current->right;
        }
        current = new TreeNode(val);
        if (val < parent->val)
            parent->left = current;
        else
            parent->right = current;

        return root;
    }
};