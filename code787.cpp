#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> cost(k + 2, vector<int>(n, INT_MAX));
        vector<vector<pair<int, int>>> inBoundFlight(n);
        for (int i = 0; i < flights.size(); i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int c = flights[i][2];
            inBoundFlight[to].push_back({from, c});
        }
        cost[0][src] = 0;
        for (int stopCnt = 1; stopCnt <= k + 1; stopCnt++)
        {
            for (int i = 0; i < n; i++)
            {
                cost[stopCnt][i] = cost[stopCnt - 1][i];
                for (int f = 0; f < inBoundFlight[i].size(); f++)
                {
                    int srcCost = cost[stopCnt - 1][inBoundFlight[i][f].first];
                    int flightCost = inBoundFlight[i][f].second;

                    if (srcCost == INT_MAX)
                        continue;
                    if (srcCost + flightCost < cost[stopCnt][i])
                    {
                        cost[stopCnt][i] = srcCost + flightCost;
                    }
                }
            }
        }

        if (cost[k + 1][dst] == INT_MAX)
            return -1;
        else
            return cost[k + 1][dst];
    }
};