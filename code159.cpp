#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int start = 0;
        int con_start = 0;
        char ch1 = s[0];
        char ch2 = 0;
        int res = INT_MIN;
        int i = 0;
        for (i = 1; i < s.length(); i++)
        {

            if (s[i] == ch1 || s[i] == ch2 || ch2 == 0)
            {
                if (s[i] != ch1 && ch2 == 0)
                    ch2 = s[i];

                if (s[i] != s[i - 1])
                    con_start = i;
            }
            else
            {
                int r = i - start;
                res = max(r, res);
                start = con_start;
                ch1 = s[start];
                ch2 = s[i];
                con_start = i;
            }
        }
        int r = i - start;
        res = max(r, res);
        return res;
    }
};