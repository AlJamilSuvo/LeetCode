#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> indexHeight;
        indexHeight.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            if(height[i]<height[indexHeight.top()]) {
                indexHeight.push()
            }
        }
    }
};