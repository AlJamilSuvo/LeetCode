#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;
        map<int, vector<int>> index_map;
        for (int i = 0; i < arr.size(); i++)
        {
            index_map[arr[i]].push_back(i);
        }
        map<int, int> distance_map;
        map<int, bool> found;
        int src = 0;
        int target = arr.size() - 1;
        queue<int> q;
        distance_map[0] = 0;
        found[0] = true;
        q.push(0);
        while (!q.empty())
        {
            int item = q.front();
            q.pop();
            int d = distance_map[item];
            vector<int> adj_list;
            if (item - 1 >= 0 && !found[item - 1])
                adj_list.push_back(item - 1);
            if (item + 1 <= target && !found[item + 1])
                adj_list.push_back(item + 1);
            for (auto index : index_map[arr[item]])
            {
                if (!found[index])
                    adj_list.push_back(index);
            }
            index_map[arr[item]].clear();

            for (auto adj : adj_list)
            {
                distance_map[adj] = d + 1;
                found[adj] = true;
                q.push(adj);
                if (adj == target)
                    return d + 1;
            }
        }
        return distance_map[target];
    }
};