#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int currentPoint;
        int insertingPoint;
        insertingPoint = 0;
        currentPoint = 0;
        for (currentPoint = 0; currentPoint < nums.size(); currentPoint++)
        {
            if (nums[currentPoint] == 0)
                continue;
            nums[insertingPoint] = nums[currentPoint];
            insertingPoint++;
        }
        for (; insertingPoint < nums.size(); insertingPoint++)
        {
            nums[insertingPoint] = 0;
        }
    }
};