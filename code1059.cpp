#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> res;
        stack<vector<int>> dfs;
        dfs.push({source});
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        while (!dfs.empty())
        {
            vector<int> path = dfs.top();
            dfs.pop();
            int lastNode = path[path.size() - 1];
            bool isNewPathFound = false;
            map<int, bool> visited;
            for (int i = 0; i < path.size(); i++)
                visited[path[i]] = true;
            for (int i = 0; i < adjList[lastNode].size(); i++)
            {

                if (!visited[adjList[lastNode][i]])
                {
                    isNewPathFound = true;
                    vector<int> newPath = path;
                    newPath.push_back(adjList[lastNode][i]);
                    dfs.push(newPath);
                }
                else
                    return false;
            }

            if (lastNode == destination && isNewPathFound)
                return false;

            if (lastNode != destination && !isNewPathFound)
                return false;
        }
        return true;
    }
};