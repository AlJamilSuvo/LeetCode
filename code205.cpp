#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mpS, mpT;
        for (int i = 0; i < s.size(); i++)
        {
            if (mpS[s[i]] == 0 && mpT[t[i]] == 0)
            {
                mpS[s[i]] = t[i];
                mpT[t[i]] = s[i];
            }
            else if (mpS[s[i]] != t[i] || mpT[t[i]] != s[i])
                return false;
        }

        return true;
    }
};