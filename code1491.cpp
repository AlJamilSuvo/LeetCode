#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int mx = INT_MIN;
        int mn = INT_MAX;
        double sum;
        int cnt = salary.size() - 2;
        for (int i = 0; i < salary.size(); i++)
        {
            mx = max(mx, salary[i]);
            mn = min(mn, salary[i]);
            sum += salary[i];
        }
        sum = sum - (mx + mn);
        return sum / cnt;
    }
};