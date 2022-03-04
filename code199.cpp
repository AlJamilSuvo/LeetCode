#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> bfsQ;
        map<TreeNode *, int> depthMap;
        bfsQ.push(root);
        depthMap[root] = 0;
        vector<int> result;
        while (!bfsQ.empty())
        {
            TreeNode *node = bfsQ.front();
            bfsQ.pop();
            int d = depthMap[node];
            if (d < result.size())
                result[d] = node->val;
            else
                result.push_back(node->val);
            if (node->left != nullptr)
            {
                bfsQ.push(node->left);
                depthMap[node->left] = d + 1;
            }
            if (node->right != nullptr)
            {
                bfsQ.push(node->right);
                depthMap[node->right] = d + 1;
            }
        }
        return result;
    }
};