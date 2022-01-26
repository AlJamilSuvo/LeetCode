#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 1;
        int right = numbers.size();
        while (left < right)
        {
            int sum = numbers[left - 1] + numbers[right - 1];
            if (sum == target)
            {
                return {left, right};
            }
            if (sum < target)
                left++;
            else
                right--;
        }
    }
};