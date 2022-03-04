#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rows;
        set<int> cols;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto r : rows)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[r][j] = 0;
            }
        }

        for (auto c : cols)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][c] = 0;
            }
        }
    }
};

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0 && i != 0 && j != 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 1; j < n; j++)
                matrix[0][j] = 0;
            for (int i = 1; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};