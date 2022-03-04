#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int unMatchedCnt = 0;
        int unMatchedIndex = -1;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[i])
                continue;
            unMatchedCnt++;
            if (unMatchedCnt > 2)
                return false;
            if (unMatchedIndex == -1)
            {
                unMatchedIndex = i;
            }
            else
            {
                char t = s1[i];
                s1[i] = s1[unMatchedIndex];
                s1[unMatchedIndex] = t;
            }
        }

        return s1 == s2;
    }
};