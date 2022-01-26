#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (jobDifficulty.size() < d)
            return -1;

        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d, -1));

        return minDifficulty(jobDifficulty, d, 0, 1, dp);
    }

    int minDifficulty(vector<int> &jobDificulty, int totalDay, int currentDayStartIndex, int currentDay, vector<vector<int>> &dp)
    {

        if (dp[currentDayStartIndex][currentDay - 1] != -1)
        {
            return dp[currentDayStartIndex][currentDay - 1];
        }

        if (currentDay == totalDay)
        {
            int hardest = -1;
            for (int i = currentDayStartIndex; i < jobDificulty.size(); i++)
                hardest = max(hardest, jobDificulty[i]);
            dp[currentDayStartIndex][currentDay - 1] = hardest;
            return hardest;
        }
        int remainingDay = totalDay - currentDay;
        int maxNextDayIndex = jobDificulty.size() - remainingDay;
        int minDiff = INT_MAX;
        for (int i = currentDayStartIndex + 1; i <= maxNextDayIndex; i++)
        {
            int hardest = -1;
            for (int j = currentDayStartIndex; j < i; j++)
                hardest = max(hardest, jobDificulty[j]);
            int diff = hardest + minDifficulty(jobDificulty, totalDay, i, currentDay + 1, dp);
            minDiff = min(diff, minDiff);
        }
        dp[currentDayStartIndex][currentDay - 1] = minDiff;

        return minDiff;
    }
};