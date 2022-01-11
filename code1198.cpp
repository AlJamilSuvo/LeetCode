#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestCommonElement(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            bool isFound = true;
            for (int j = 1; j < m; j++)
            {
                isFound = hasElementInRow(mat[0][i], mat[j], 0, n - 1);
                if (!isFound)
                    break;
            }
            if (isFound)
                return mat[0][i];
        }
        return -1;
    }
    bool hasElementInRow(int target, vector<int> &row, int left, int right)
    {
        if (left > right)
            return false;
        if (target < row[left] || target > row[right])
            return false;
        int mid = (left + right) / 2;
        if (row[mid] == target)
            return true;
        if (row[mid] > target)
            return hasElementInRow(target, row, left, mid - 1);
        else
            return hasElementInRow(target, row, mid + 1, right);
    }
};