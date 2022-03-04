#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        map<Node *, bool> visited;
        map<Node *, Node *> cloneMap;
        stack<Node *> dfs;
        dfs.push(node);
        while (!dfs.empty())
        {
            Node *oldNode = dfs.top();
            dfs.pop();
            Node *newNode = cloneMap[oldNode];
            if (newNode == nullptr)
            {
                newNode = new Node(oldNode->val);
                cloneMap[oldNode] = newNode;
            }

            if (!visited[oldNode])
            {
                visited[oldNode] = true;
                for (int i = 0; i < oldNode->neighbors.size(); i++)
                {
                    Node *on = oldNode->neighbors[i];
                    Node *nn = cloneMap[on];
                    if (nn == nullptr)
                    {
                        nn = new Node(on->val);
                        cloneMap[on] = nn;
                    }

                    newNode->neighbors.push_back(nn);
                    dfs.push(on);
                }
            }
        }

        return cloneMap[node];
    }
};