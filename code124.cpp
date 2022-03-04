#include "tree_node_util.hpp"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }

    void maxPathSum(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
            return;

        if (node->val > maxSum)
        {
            maxSum = node->val;
        }

        if (node->left == nullptr && node->right == nullptr)
            return;

        maxPathSum(node->right, maxSum);
        maxPathSum(node->left, maxSum);
        int a = 0;
        int b = 0;
        int x = INT_MIN;
        int y = INT_MIN;
        if (node->left != nullptr)
        {
            a = node->left->val;
            x = node->left->val;
        }
        if (node->right != nullptr)
        {
            b = node->right->val;
            y = node->right->val;
        }
        int sum1 = a + node->val + b;
        if (sum1 > maxSum)
        {
            maxSum = sum1;
        }

        int sum2 = node->val + b;
        if (sum2 > maxSum)
        {
            maxSum = sum2;
        }

        int sum3 = a + node->val;
        if (sum3 > maxSum)
        {
            maxSum = sum3;
        }
        node->val = max(node->val, max(sum2, sum3));
    }
};