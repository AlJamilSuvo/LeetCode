#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                int a = 0;
                if (j - 1 >= 0)
                    a = res[i - 1][j - 1];
                int b = 0;
                if (j < i)
                    b = res[i - 1][j];
                int s = a + b;
                row.push_back(s);
            }
            res.push_back(row);
        }
        return res;
    }
};