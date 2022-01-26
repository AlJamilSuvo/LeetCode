#include "tree_node_util.hpp"

class Solution
{
public:
    int countUnivalSubtrees(TreeNode *root)
    {
        int treeCount=0;
        int unival=0;
        countUnivalSubtrees(root, treeCount, unival);
        return treeCount;
    }

    void countUnivalSubtrees(TreeNode *node, int &subTreeCount, int &unival)
    {
        if (node == nullptr)
        {
            subTreeCount = 0;
            return;
        }

        int leftUnival = node->val;
        int leftTreeCount = node->val;

        int rightUnival = node->val;
        int rightTreeCount = node->val;

        countUnivalSubtrees(node->left, leftTreeCount, leftUnival);
        countUnivalSubtrees(node->right, rightTreeCount, rightUnival);

        if (leftUnival == rightUnival && leftUnival == node->val)
        {
            subTreeCount = 1+leftTreeCount+rightTreeCount;
            unival = node->val;
        }
        else
        {
            subTreeCount = leftTreeCount + rightTreeCount;
            unival = 1009;
        }
    }
};