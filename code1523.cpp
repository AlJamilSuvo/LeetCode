#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int diff = high - low + 1;

        int cnt = diff / 2;

        if (diff % 2 == 1 && low % 2 == 1)
            cnt++;

        return cnt;
    }
};