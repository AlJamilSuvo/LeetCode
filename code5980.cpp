#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res;

        int len = ceil(((float)s.size()) / (float)k);
        for (int i = 0; i < len; i++)
        {
            string r = "";
            for (int j = i * k; j < (i + 1) * k; j++)
            {
                if (j < s.size())
                    r += s[j];
                else
                    r += fill;
            }
            res.push_back(r);
        }
        return res;
    }
};