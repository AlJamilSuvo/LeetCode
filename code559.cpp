#include "n_arr_util.hpp"

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        map<Node *, int> depth;
        int maxDepth = 0;
        stack<Node *> dfs;
        depth[root] = 1;
        dfs.push(root);
        while (!dfs.empty())
        {
            Node *node = dfs.top();
            dfs.pop();
            int d = depth[node];
            maxDepth = max(d, maxDepth);
            for (int i = 0; i < node->children.size(); i++)
            {
                depth[node->children[i]] = d + 1;
                dfs.push(node->children[i]);
            }
        }
        return maxDepth;
    }
};