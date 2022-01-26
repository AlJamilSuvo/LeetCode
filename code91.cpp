#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.length() + 1);
        dp[0] = 0;
        if (s[0] >= '1' && s[0] <= '9')
            dp[1] = 1;
        for (int i = 1; i < s.length(); i++)
        {
            int cnt = 0;
            if (s[i] >= '1' && s[i] <= '9')
                cnt += dp[i];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
                cnt += dp[i - 1];
            dp[i + 1] = cnt;
        }
        return dp[s.length()];
    }
};