#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int position = -1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            cout << mid << endl;
            if (nums[mid] == 0)
            {
                position = mid;
                break;
            }
            if (nums[mid] > 0)
            {
                right = mid;
            }
            else
                left = mid;
        }

        if (position == -1)
            position = right;
        right = position;
        left = position - 1;
        vector<int> result;
        while (left >= 0 || right < nums.size())
        {
            int s1 = 10e4 + 1;
            int s2 = 10e4 + 1;
            if (left >= 0)
                s1 = nums[left];

            if (right < nums.size())
                s2 = nums[right];

            if (abs(s1) < abs(s2))
            {
                result.push_back(s1 * s1);
                left--;
            }
            else
            {
                result.push_back(s2 * s2);
                right++;
            }
        }
        return result;
    }
};

class Solution1
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(nums.size());
        int position = nums.size() - 1;
        while (position>=0)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                result[position] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[position] = nums[right] * nums[right];
                right--;
            }
            position--;
        }
        return result;
    }
};

int main()
{
    vector<int> i1 = {-7, -3, 2, 3, 11};
    Solution s;
    s.sortedSquares(i1);
}