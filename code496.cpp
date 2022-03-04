#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums2.size(); i++)
        {
            indexMap[nums2[i]] = i;
        }

        vector<int> res;

        for (int i = 0; i < nums1.size(); i++)
        {

            int idx = indexMap[nums1[i]];

            int val = -1;
            for (int j = idx + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                {
                    val = nums2[j];
                    break;
                }
            }
            res.push_back(val);
            
        }
        return res;
    }
};