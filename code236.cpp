#include "tree_node_util.hpp"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        map<TreeNode *, int> distance;
        map<TreeNode *, TreeNode *> parent;
        int foundCount = 0;
        queue<TreeNode *> bfsQ;

        distance[root] = 0;
        parent[root] = nullptr;
        bfsQ.push(root);

        while (!bfsQ.empty())
        {
            TreeNode *node = bfsQ.front();
            bfsQ.pop();
            int d = distance[node];
            if (node->left != nullptr)
            {
                parent[node->left] = node;
                distance[node->left] = d + 1;
                bfsQ.push(node->left);
                if (node->left == p || node->left == q)
                    foundCount++;
            }

            if (node->right != nullptr)
            {
                parent[node->right] = node;
                distance[node->right] = d + 1;
                bfsQ.push(node->right);
                if (node->right == p || node->right == q)
                    foundCount++;
            }

            if (foundCount == 2)
                break;
        }

        while (p != q)
        {
            if (distance[p] > distance[q])
            {
                p = parent[p];
            }
            else if (distance[q] > distance[p])
            {
                q = parent[q];
            }
            else
            {
                p = parent[p];
                q = parent[q];
            }
        }

        return p;
    }
};