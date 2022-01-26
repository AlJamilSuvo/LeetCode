#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        stack<int> dfs;
        dfs.push(source);
        while (!dfs.empty())
        {
            int cur = dfs.top();
            if (cur == destination)
                return true;
            dfs.pop();
            if (!visited[cur])
            {
                for (int i = 0; i < adjList[cur].size(); i++)
                {
                    if (adjList[cur][i] == destination)
                        return true;
                    if (!visited[adjList[cur][i]])
                        dfs.push(adjList[cur][i]);
                }
                visited[cur] = true;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        queue<int> bfs;
        bfs.push(source);
        while (!bfs.empty())
        {
            int cur = bfs.front();
            if (cur == destination)
                return true;
            bfs.pop();
            if (!visited[cur])
            {
                for (int i = 0; i < adjList[cur].size(); i++)
                {
                    if (adjList[cur][i] == destination)
                        return true;
                    if (!visited[adjList[cur][i]])
                        bfs.push(adjList[cur][i]);
                    
                }
                visited[cur] = true;
            }
        }
        return false;
    }
};