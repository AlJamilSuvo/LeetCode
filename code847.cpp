#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        if (graph.size() == 1)
            return 0;
        int n = graph.size();
        int endingMask = (1 << n) - 1;
        vector<pair<int, int>> que;
        vector<vector<bool>> seen(n, vector<bool>(endingMask, false));
        for (int i = 0; i < n; i++)
        {
            que.push_back({i, 1 << i});
            seen[i][1 << i] = true;
        }
        int pathLen = 0;
        while (!que.empty())
        {
            vector<pair<int, int>> nextQue;
            for (auto pr : que)
            {
                int p = pr.first;
                int mask = pr.second;

                for (auto ngbr : graph[p])
                {
                    int nextMask = mask | (1 << ngbr);

                    if (nextMask == endingMask)
                        return 1 + pathLen;
                    if (!seen[ngbr][nextMask])
                    {
                        seen[ngbr][nextMask] = true;
                        nextQue.push_back({ngbr, nextMask});
                    }
                }
            }
            pathLen++;
            que = nextQue;
        }
        return -1;
    }
};

int main()
{

    vector<vector<int>> inp1 = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    Solution s;
    s.shortestPathLength(inp1);

    // int n = 5;
    // int endingMask = (1 << n) - 1;
    // cout << endingMask << endl;
    // bitset<8> bs(endingMask);
    // cout << bs << endl;
}