#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int nextSlopeIndex = 0;
        map<pair<double, double>, set<int>> linePointMap;
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];

                double m = (y2 - y1) / (x2 - x1);
                double c = y1 = m * x1;
                pair<double, double> line = {m, c};
                linePointMap[line].insert(i);
                linePointMap[line].insert(j);
                if (linePointMap[line].size() > res)
                {
                    res = linePointMap[line].size();
                }
            }
        }
        return res;
    }
};