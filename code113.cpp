#include <bits/stdc++.h>
#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> currentPath;
        pathSum(root, targetSum, res, currentPath);
        return res;
    }

    void pathSum(TreeNode *node, int targetSum, vector<vector<int>> &res, vector<int> currentPath)
    {
        if (node == nullptr)
            return;
        currentPath.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            if (node->val == targetSum)
            {
                res.push_back(currentPath);
            }
        }
        else
        {
            pathSum(node->left, targetSum - node->val, res, currentPath);
            pathSum(node->right, targetSum - node->val, res, currentPath);
        }
    }
};