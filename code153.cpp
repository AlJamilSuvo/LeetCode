#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return min(nums[0], nums[1]);
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();

        while (left <= right)
        {
            if (left == right)
                return nums[left];
            if (right == left + 1)
            {
                return min(nums[left], nums[right]);
            }
            int mid = left + (right - left) / 2;

            int prev = nums[(mid - 1 + n) % n];
            int next = nums[(mid + 1 + n) % n];
            if (nums[mid] < prev && nums[mid] < next)
                return nums[mid];

            // cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            if (nums[mid] < nums[left] && nums[mid] < nums[left] && nums[right] < nums[left])
            {
                left = left + 1;
                right = mid;
                // cout << "case 1" << endl;
            }
            else if (nums[right] < nums[left] && nums[right] < nums[mid] && nums[left] < nums[mid])
            {
                left = mid + 1;
                right = right;
                // cout << "case 2" << endl;
            }
            else if (nums[left] < nums[mid] && nums[left] < nums[right] && nums[mid] < nums[right])
            {
                left = left;
                right = mid - 1;
                // cout << "case 3" << endl;
            }
            else
            {
                // cout << "unknown case" << endl;
            }
        }
        return 0;
    }
};