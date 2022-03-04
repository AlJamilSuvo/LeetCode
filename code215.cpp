#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Quick Select

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
    }

    int quickSelect(vector<int> &nums, int left, int right, int targetIndex)
    {
        
    }
};