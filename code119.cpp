#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        prev.push_back(1);
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                int a = 0;
                if (j - 1 >= 0)
                    a = prev[j - 1];
                int b = 0;
                if (j < i)
                    b = prev[j];
                int s = a + b;
                row.push_back(s);
            }
            prev = row;
        }
        return prev;
    }
};