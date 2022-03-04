#include "tree_node_util.hpp"

class Solution
{
    double result = -1;

public:
    double maximumAverageSubtree(TreeNode *root)
    {
        getSubTreeSumAndSize(root);
        return result;
    }

    pair<double, double> getSubTreeSumAndSize(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        auto l = getSubTreeSumAndSize(node->left);
        auto r = getSubTreeSumAndSize(node->right);
        double totalSum = l.first + r.first + node->val;
        double cnt = l.second + r.second + 1;
        double avg = totalSum / cnt;
        if (avg > result)
            result = avg;
        return {totalSum, cnt};
    }
};