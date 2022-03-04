#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int res = 0;
        for (int i = 0; i < columnTitle.size(); i++)
        {
            int c = columnTitle[i] - 'A' + 1;
            res = res * 26 + c;
        }
        return res;
    }
};