#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int id1 = m - 1;
        int id2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--)
        {
            int v1 = INT_MIN;
            int v2 = INT_MIN;
            if (id1 >= 0)
                v1 = nums1[id1];
            if (id2 >= 0)
                v2 = nums2[id2];

            int mx = max(v1, v2);
            if (v1 == mx)
                id1--;
            else if (v2 == mx)
                id2--;
            nums1[i] = mx;
        }
    }
};