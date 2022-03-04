#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        stack<vector<int>> dfs;
        vector<vector<int>> result;
        int des = graph.size() - 1;
        dfs.push({0});
        while (!dfs.empty())
        {

            vector<int> current_path = dfs.top();
            dfs.pop();
            int last_node = current_path[current_path.size() - 1];
            if (last_node == des)
            {
                result.push_back(current_path);
                continue;
            }
            map<int, bool> visited;
            for (int i = 0; i < current_path.size(); i++)
                visited[current_path[i]] = true;
            for (int i = 0; i < graph[last_node].size(); i++)
            {
                int node = graph[last_node][i];
                if (!visited[node])
                {
                    vector<int> new_path = current_path;
                    new_path.push_back(node);
                    dfs.push(new_path);
                }
            }
        }

        return result;
    }
};