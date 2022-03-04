#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int index;
    int parent;
    int64_t distance = INT_MAX;
    bool visited = false;
    vector<int> adjList;
    vector<int> weight;
};

class NodeComperator
{
public:
    bool operator()(Node *n1, Node *n2)
    {
        if (n1->visited != n2->visited)
        {
            return n1->visited;
        }
        else
            return n1->distance > n2->distance;
    }
};

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        map<int, Node *> nodeMap;
        for (int i = 1; i <= n; i++)
        {
            nodeMap[i] = new Node();
            nodeMap[i]->index = i;
        }
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            nodeMap[u]->adjList.push_back(v);
            nodeMap[u]->weight.push_back(w);
        }
        nodeMap[k]->distance = 0;
        priority_queue<Node *, vector<Node *>, NodeComperator> q;
        for (int i = 1; i <= k; i++)
        {
            q.push(nodeMap[i]);
        }

        int visitCnt = 0;

        while (!q.empty())
        {
            Node *n = q.top();
            q.pop();
            for (int i = 0; i < n->adjList.size(); i++)
            {

                int v = n->adjList[i];
                int d = n->weight[i];

                if (n->distance + d < nodeMap[v]->distance)
                {
                    nodeMap[v]->distance = n->distance + d;
                    q.push(nodeMap[v]);
                }
            }
            n->visited = true;
        }

        int64_t res = -1;
        for (int i = 1; i <= n; i++)
        {
            res = max(nodeMap[i]->distance, res);
        }
        if (res == INT_MAX)
            return -1;
        else
            return res;
    }
};