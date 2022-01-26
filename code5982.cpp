#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, long long> dp;
    map<int, bool> calculated;

    long long
    mostPoints(vector<vector<int>> &questions)
    {
        return mostPoints(questions, 0);
    }

    long long mostPoints(vector<vector<int>> &questions, int startIndex)
    {
        if (calculated[startIndex])
            return dp[startIndex];
        if (startIndex >= questions.size())
        {
            return 0;
        }
        if (startIndex == questions.size() - 1)
        {
            calculated[startIndex] = true;
            dp[startIndex] = questions[startIndex][0];
        }

        int p = questions[startIndex][0];
        int b = questions[startIndex][1];
        long long u = p + mostPoints(questions, startIndex + b + 1);
        long long a = mostPoints(questions, startIndex + 1);
        long long res = max(u, a);
        calculated[startIndex] = true;
        dp[startIndex] = res;
        return res;
    }
};