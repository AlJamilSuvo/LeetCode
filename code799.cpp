#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> amount(102, vector(102, 0.0));
        amount[0][0] = poured;
        for (int i = 0; i <= query_row; i++)
        {
            for (int j = 0; j <= query_glass; j++)
            {
                double drop = (amount[i][j] - 1) / 2.0;
                if (drop > 0)
                {
                    amount[i + 1][j] += drop;
                    amount[i + 1][j + 1] += drop;
                }
            }
        }
        return min(1.0, amount[query_row][query_glass]);
    }
};