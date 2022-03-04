#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        map<Node *, int> distance;
        distance[root] = 0;
        queue<Node *> bfsQ;
        bfsQ.push(root);
        while (!bfsQ.empty())
        {
            Node *node = bfsQ.front();
            bfsQ.pop();
            int d = distance[node];
            if (res.size() <= d)
                res.push_back({});
            res[d].push_back(node->val);
            for (int i = 0; i < node->children.size(); i++)
            {
                distance[node->children[i]] = d + 1;
                bfsQ.push(node->children[i]);
            }
        }

        return res;
    }
};