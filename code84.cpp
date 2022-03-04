#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = INT_MIN;
        stack<int> indexStk;
        stack<int> valueStk;
        indexStk.push(-1);
        valueStk.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while (valueStk.top() > heights[i])
            {
                int h = valueStk.top();
                valueStk.pop();
                indexStk.pop();
                int leftIndex = indexStk.top();
                int w = i - leftIndex - 1;
                if (h * w > maxArea)
                    maxArea = h * w;
            }
            valueStk.push(heights[i]);
            indexStk.push(i);
        }
        int rightLimit = heights.size();
        while (valueStk.top() >= 0)
        {
            int h = valueStk.top();
            valueStk.pop();
            indexStk.pop();
            int leftLimit = indexStk.top();
            int w = rightLimit - leftLimit - 1;
            if (h * w > maxArea)
                maxArea = h * w;
        }

        return maxArea;
    }
};