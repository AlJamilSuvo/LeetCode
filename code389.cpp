#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> sCntMap, tCntMap;
        for (int i = 0; i < s.length(); i++)
        {
            sCntMap[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            tCntMap[t[i]]++;
            if (tCntMap[t[i]] > sCntMap[t[i]])
                return t[i];
        }

        return ' ';
    }
};