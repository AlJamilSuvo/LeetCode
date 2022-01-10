#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> centriods;
        if (n < 2)
        {
            for (int i = 0; i < n; i++)
                centriods.push_back(i);
            return centriods;
        }
        map<int, set<int>> adj_list;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj_list[u].insert(v);
            adj_list[v].insert(u);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (adj_list[i].size() == 1)
                leaves.push_back(i);
        }
        int remaining = n;
        while (remaining > 2)
        {
            vector<int> newLeaves;
            remaining -= leaves.size();
            for (auto leaf : leaves)
            {
                for (auto neighbour : adj_list[leaf])
                {
                    adj_list[neighbour].erase(leaf);
                    if (adj_list[neighbour].size() == 1)
                        newLeaves.push_back(neighbour);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main()
{
    vector<vector<int>> t1 = {{1, 0},
                              {1, 2},
                              {1, 3}};

    vector<vector<int>> t2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};

    Solution s;
    vector<int> v1 = s.findMinHeightTrees(4, t1);
    for (auto node : v1)
        cout << node << " ";
    cout << endl;

    vector<int> v2 = s.findMinHeightTrees(6, t2);
    for (auto node : v2)
        cout << node << " ";
    cout << endl;
}