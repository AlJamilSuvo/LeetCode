#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        map<pair<int, int>, bool> foundMap;
        int result = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int64_t a = nums[i];
                int64_t b = nums[j];
                int64_t c = a - b;
                if (c == k)
                {
                    pair<int, int> res = {a, b};
                    if (!foundMap[res])
                    {
                        result++;
                        foundMap[res] = result;
                    }
                }
                if (c == (k * -1) && k != 0)
                {
                    pair<int, int> res = {b, a};
                    if (!foundMap[res])
                    {
                        result++;
                        foundMap[res] = result;
                    }
                }
            }
        }
        return result;
    }
};

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            if (findNums(nums, i + 1, nums.size() - 1, nums[i] + k))
                result++;

            // if (findNums(nums, i + 1, nums.size() - 1, nums[i] - k))
            //     result++;
        }
        return result;
    }

    bool findNums(vector<int> &nums, int left, int right, int target)
    {
        if (left > right)
            return false;
        if (left == right)
        {
            return nums[left] == target;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;

        if (nums[mid] < target)
        {
            return findNums(nums, mid + 1, right, target);
        }
        else
            return findNums(nums, left, mid - 1, target);
    }
};

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int result = 0;
        while (left < nums.size() && right < nums.size())
        {
            if (left >= right)
            {
                right = left + 1;
                continue;
            }
            if (left > 0 && nums[left] == nums[left - 1]){
                left++;
                continue;
            }
            int diff = nums[right] - nums[left];
            if (diff == k)
            {
                result++;
                left++;
            }
            else if (diff < k)
            {
                right++;
            }
            else
            {
                left++;
            }
        }

        return result;
    }
};