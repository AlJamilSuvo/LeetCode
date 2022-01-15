#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool isOneFound = false;
        bool isPrevOne = false;
        for (auto ch : s)
        {
            if (ch == '1')
            {
                if (!isPrevOne && isOneFound)
                    return false;
                isOneFound = true;
            }

            isPrevOne = ch == '1';
        }
        return true;
    }
};