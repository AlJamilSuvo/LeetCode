#include "tree_node_util.hpp"

class Solution
{
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode *left = upsideDownBinaryTree(root->left);
        TreeNode *oldRootParent = left;
        while (oldRootParent->right != nullptr)
        {
            oldRootParent = oldRootParent->right;
        }
        oldRootParent->right = root;
        oldRootParent->left = root->right;
        root->left = nullptr;
        root->right = nullptr;
        return left;
    }
};