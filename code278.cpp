#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int statBad = 0;
    int firstBadVersion(int n)
    {
        int start = 1;
        int end = n;
        while (start != end)
        {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    bool isBadVersion(int n)
    {
        return n >= statBad;
    }
};

int main()
{
    Solution s;
    s.statBad = 1;
    cout << s.firstBadVersion(1) << endl;
}