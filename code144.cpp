#include <bits/stdc++.h>
#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
             if (node->right != nullptr)
                stk.push(node->right);
            if (node->left != nullptr)
                stk.push(node->left);
           
        }

        return res;
    }
};