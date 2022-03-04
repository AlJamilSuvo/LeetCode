#include <bits/stdc++.h>
using namespace std;

class Solution
{

    map<pair<int, int>, int64_t> dp;
    map<pair<int, int>, bool> seen;

public:
    int minimumTime(string s)
    {
        int64_t res;
        int mid = s.length() / 2;
        if (s[mid] == '1')
            res = 1;

        int left = mid - 1;
        int right = mid + 1;
        while (left >= 0 && right < s.length())
        {
            int removing = 2 + res;
            int keeping = s[left] == '1' ? 1 : 0;
            keeping += s[right] == '1' ? 1 : 0;
            keeping = keeping + 2 * res;
            res = min(removing, keeping);
            left--;
            right++;
        }

        if (right != s.length())
        {
            res = res + 1;
        }
        return res;
    }
};