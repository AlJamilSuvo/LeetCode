#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp;
        dp.push_back({triangle[0]});
        int res;
        for (int i = 1; i < triangle.size(); i++)
        {
            res = INT_MAX;
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                int a = INT_MAX;
                if (j != 0)
                    a = dp[i - 1][j - 1];
                int b = INT_MAX;
                if (j != i)
                    b = dp[i - 1][j];
                row.push_back(min(a, b) + triangle[i][j]);
                res = min(res, row[j]);
            }
            dp.push_back(row);
        }
        return res;
    }
};

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> dp;
        int n = triangle.size() - 1;
        for (int i = 0; i < triangle[n].size(); i++)
        {
            dp.push_back(triangle[n][i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> row;
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int a = triangle[i][j] + min(dp[j], dp[j + 1]);
                row.push_back(a);
            }
            dp = row;
        }

        return dp[0];
    }
};

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size() - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};
