#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> q;
        visitBST(root, q);
        TreeNode *newRoot = q.front();
        newRoot->left = nullptr;
        newRoot->right = nullptr;
        TreeNode *prev = newRoot;
        q.pop();
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            node->left = nullptr;
            node->right = nullptr;
            prev->right = node;
            prev = node;
        }
        return newRoot;
    }

    void visitBST(TreeNode *node, queue<TreeNode *> &q)
    {
        if (node == nullptr)
            return;
        visitBST(node->left, q);
        q.push(node);
        visitBST(node->right, q);
    }
};
