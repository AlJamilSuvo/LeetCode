#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;
        bool foundInc = false;
        bool foundDec = false;

        for (int i = 1; i < arr.size(); i++)
        {
            cout<<arr[i]<<endl;
            if (arr[i] == arr[i - 1])
                return false;
            if (!foundInc && arr[i] < arr[i - 1])
                return false;
            if (foundDec && arr[i] > arr[i - 1])
                return false;
            if (arr[i] > arr[i - 1])
                foundInc = true;
            if (arr[i] < arr[i - 1])
                foundDec = true;
        }

        return foundDec && foundInc;
    }
};