#include "n_arr_util.hpp"

// class Solution
// {
// public:
//     vector<int> preorder(Node *root)
//     {
//         vector<int> res;
//         preorder(root, res);
//         return res;
//     }

//     void preorder(Node *node, vector<int> &res)
//     {
//         if (node == nullptr)
//             return;
//         res.push_back(node->val);
//         for (int i = 0; i < node->children.size(); i++)
//         {
//             preorder(node->children[i], res);
//         }
//     }
// };

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<Node *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            Node *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                stk.push(node->children[i]);
            }
        }

        return res;
    }
};