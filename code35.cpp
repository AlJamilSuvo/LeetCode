
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (target <= nums[left])
            return left;
        else
            return left + 1;
    }
};

int main()
{
    vector<int> i1 = {1, 3, 5, 6};
    Solution s;
    cout<<s.searchInsert(i1,5)<<endl;
    cout<<s.searchInsert(i1,2)<<endl;
    cout<<s.searchInsert(i1,4)<<endl;
    cout<<s.searchInsert(i1,7)<<endl;
}