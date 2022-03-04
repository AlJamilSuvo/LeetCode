#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    map<int, int> root;
    map<int, int> rank;

public:
    DisjointSet(const vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            root[nums[i]] = nums[i];
            rank[nums[i]] = 1;
        }
    }
    int find(int x)
    {
        if (root[x] != x)
        {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    int make_union(int x, int y)
    {

        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] >= rank[rootY])
            {
                root[rootY] = rootX;
                rank[rootX] = rank[rootX] + rank[rootY];
                return rank[rootX];
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] = rank[rootX] + rank[rootY];
                return rank[rootY];
            }
        }
        else
        {
            return rank[rootX];
        }
    }
};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        DisjointSet ds(nums);
        map<int, bool> found;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int s = 1;
            int num = nums[i];
            found[num] = true;
            if (found[num - 1])
            {
                s = max(s, ds.make_union(num - 1, num));
            }
            if (found[num + 1])
            {
                s = max(s, ds.make_union(num, num + 1));
            }
            result = max(s, result);
        }
        return result;
    }
};