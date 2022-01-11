#include "tree_node_util.hpp"

using namespace std;

class Solution
{
public:
    int equalToDescendants(TreeNode *root)
    {
        int result_count = 0;
        int64_t sum = 0;
        getSumAndCount(root, sum, result_count);
        return result_count;
    }

    void getSumAndCount(TreeNode *node, int64_t &sum, int &count)
    {
        if (node == nullptr)
        {
            return;
        }
        int64_t left = 0, right = 0;
        getSumAndCount(node->left, left, count);
        getSumAndCount(node->right, right, count);
        sum = left + right + node->val;
        if (left + right == node->val)
        {
            count += 1;
        }
    }
};