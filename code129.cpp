#include "tree_node_util.hpp"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int totalSum = 0;
        sumNumbers(root, 0, totalSum);
        return totalSum;
    }

    void sumNumbers(TreeNode *node, int currentSum, int &totalSum)
    {
        if (node == nullptr)
            return;
        currentSum = currentSum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            totalSum += currentSum;
        }
        else
        {
            if (node->left != nullptr)
                sumNumbers(node->left, currentSum, totalSum);

            if (node->right != nullptr)
                sumNumbers(node->right, currentSum, totalSum);
        }
    }
};