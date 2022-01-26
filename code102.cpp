#include "tree_node_util.hpp"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        map<TreeNode *, int> distanceMap;
        queue<TreeNode *> que;
        distanceMap[root] = 0;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();

            int d = distanceMap[node];
            if (result.size() < d + 1)
            {
                result.push_back(vector<int>());
            }
            result[d].push_back(node->val);
            if (node->left != nullptr)
            {
                distanceMap[node->left] = d + 1;
                que.push(node->left);
            }

            if (node->right != nullptr)
            {
                distanceMap[node->right] = d + 1;
                que.push(node->right);
            }
        }

        return result;
    }
};