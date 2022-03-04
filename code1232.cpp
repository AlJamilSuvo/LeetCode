#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        double slop = INT_MAX;
        if (dx != 0)
        {
            slop = (double)dy / (double)dx;
        }

        for (int i = 2; i < coordinates.size(); i++)
        {
            dy = coordinates[i][1] - coordinates[i - 1][1];
            dx = coordinates[i][0] - coordinates[i - 1][0];
            double s = INT_MAX;
            if (dx != 0)
            {
                s = (double)dy / (double)dx;
            }

            if(slop!=s) return false;
        }
        return true;
    }
};