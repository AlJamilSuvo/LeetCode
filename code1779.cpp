#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int distance = INT_MAX;
        int index = -1;

        for (int i = 0; i < points.size(); i++)
        {
            if (x == points[i][0])
            {
                if (abs(y - points[i][1]) < distance)
                {
                    distance = abs(y - points[i][1]);
                    index = i;
                }
            }
            if (y == points[i][1])
            {
                if (abs(x - points[i][0]) < distance)
                {
                    distance = abs(x - points[i][0]);
                    index = i;
                }
            }
        }
        return index;
    }
};