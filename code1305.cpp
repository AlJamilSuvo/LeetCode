#include "tree_node_util.hpp"

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> r1, r2;
        getInOrderList(root1, r1);
        getInOrderList(root2, r2);
        int i = 0;
        int j = 0;
        vector<int> r;
        while (i < r1.size() || j < r2.size())
        {
            int v1 = INT_MAX;
            int v2 = INT_MAX;

            if (i < r1.size())
                v1 = r1[i];

            if (j < r2.size())
                v2 = r2[j];

            if (v1 < v2)
            {
                r.push_back(v1);
                i++;
            }
            else
            {
                r.push_back(v2);
                j++;
            }
        }
        return r;
    }

    void getInOrderList(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        getInOrderList(root->left, res);
        res.push_back(root->val);
        getInOrderList(root->right, res);
    }
};