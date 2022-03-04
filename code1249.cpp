#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        vector<bool> keep(s.length(), false);
        stack<int> begainIndex;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '(' && s[i] != ')')
            {
                keep[i] = true;
            }
            if (s[i] == '(')
            {
                begainIndex.push(i);
                keep[i] = false;
            }
            if (s[i] == ')')
            {
                if (begainIndex.empty())
                    keep[i] = false;
                else
                {
                    keep[begainIndex.top()] = true;
                    keep[i] = true;
                    begainIndex.pop();
                }
            }
        }

        string res;
        for (int i = 0; i < s.length(); i++)
        {
            if (keep[i])
                res += s[i];
        }
        return res;
    }
};