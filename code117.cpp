#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        queue<Node *> bfsQue;
        vector<Node *> link;
        map<Node *, int> distanceMap;
        distanceMap[root] = 0;
        bfsQue.push(root);
        int currentDistance = 0;
        while (!bfsQue.empty())
        {
            Node *node = bfsQue.front();
            bfsQue.pop();
            int d = distanceMap[node];
            if (d > currentDistance)
            {

                for (int i = 0; i < link.size() - 1; i++)
                {
                    link[i]->next = link[i + 1];
                }
                link.clear();
                currentDistance = d;
            }
            link.push_back(node);
            if (node->left != nullptr)
            {
                bfsQue.push(node->left);
                distanceMap[node->left] = d + 1;
            }

            if (node->right != nullptr)
            {
                bfsQue.push(node->right);
                distanceMap[node->right] = d + 1;
            }
        }

        for (int i = 0; i < link.size() - 1; i++)
        {
            link[i]->next = link[i + 1];
        }
        link.clear();

        return root;
    }
};