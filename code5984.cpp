#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSum(int num)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < 4; i++)
        {
            int d = num % 10;
            q.push(d);
            num = num / 10;
        }
        int d1, d2, d3, d4;
        d1 = q.top();
        q.pop();
        d2 = q.top();
        q.pop();

        d3 = q.top();
        q.pop();
        d4 = q.top();
        q.pop();

        int res1 = d1 * 10 + d3;
        int res2 = d2 * 10 + d4;

        return res1 + res2;
    }
};