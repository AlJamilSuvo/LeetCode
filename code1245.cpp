#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int treeDiameter(vector<vector<int>> &edges)
    {
        map<int, vector<int>> adj_list;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        auto res1 = get_furthest_node(0, adj_list);
        auto result = get_furthest_node(res1.first, adj_list);
        return result.second;
    }

    pair<int, int> get_furthest_node(int start, map<int, vector<int>> &adj_list)
    {
        map<int, int> distance_map;
        map<int, bool> found;
        queue<int> que;
        int last_node;
        que.push(start);
        distance_map[start] = 0;
        found[start] = true;
        int max_distance = 0;
        while (!que.empty())
        {
            int parent = que.front();
            que.pop();
            int distance = distance_map[parent] + 1;
            for (auto adj : adj_list[parent])
            {
                if (!found[adj])
                {
                    found[adj] = true;
                    que.push(adj);
                    distance_map[adj] = distance;
                    if (distance > max_distance)
                    {
                        max_distance = distance;
                        last_node = adj;
                    }
                }
            }
        }

        return pair<int, int>(last_node, max_distance);
    }
};

int main()
{
    vector<vector<int>> edges1 = {{0, 1},
                                  {1, 2},
                                  {2, 3},
                                  {1, 4},
                                  {4, 5}};

    Solution s;
    cout << s.treeDiameter(edges1) << endl;
}