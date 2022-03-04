#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> cnt1;
        unordered_map<char, int> cnt2;
        for (int i = 0; i < s1.length(); i++)
        {
            cnt1[s1[i]]++;
        }
        int start = 0;
        int cur = 0;
        while (cur < s2.length())
        {
            // cout << s2[start] << " " << s2[cur] << endl;
            if (cur - start == s1.length())
                return true;
            cnt2[s2[cur]]++;
            // cout << cnt2[s2[cur]] << " " << cnt1[s2[cur]] << endl;
            if (cnt2[s2[cur]] > cnt1[s2[cur]])
            {
                while (cnt2[s2[cur]] > cnt1[s2[cur]])
                {
                    cnt2[s2[start]]--;
                    start++;
                }
                cur++;
            }
            else
                cur++;
        }
        return cur - start == s1.length();
    }
};