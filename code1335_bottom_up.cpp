#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (jobDifficulty.size() < d)
            return -1;

        int dp[jobDifficulty.size()][d + 1];
        memset(dp, -1, sizeof(dp));
        int hardest = -1;
        for (int job = jobDifficulty.size() - 1; job >= 0; job--)
        {
            hardest = max(hardest, jobDifficulty[job]);
            dp[job][d] = hardest;
            cout << job << " " << d << " " << dp[job][d] << endl;
        }

        if (d == 1)
            return hardest;

        for (int day = d - 1; day >= 1; day--)
        {
            cout << day << endl;
            for (int job = day - 1; job < jobDifficulty.size() - (d - day); job++)
            {

                cout << day << " " << job << endl;

                int hardest = jobDifficulty[job];
                int minDiff = INT_MAX;
                for (int nextDayStartIndex = job + 1; nextDayStartIndex < jobDifficulty.size(); nextDayStartIndex++)
                {
                    cout << nextDayStartIndex << " " << (day + 1) << " " << dp[nextDayStartIndex][day+1] << endl;
                    if (dp[nextDayStartIndex][day + 1] == -1)
                        break;
                    minDiff = min(minDiff, hardest + dp[nextDayStartIndex][day + 1]);
                    hardest = max(hardest, jobDifficulty[nextDayStartIndex]);
                }
                dp[job][day] = minDiff;
                cout << dp[job][day] << endl;
                if (job == 0 && day == 1)
                    return dp[job][day];
            }
        }
        return dp[0][1];
    }
};

int main()
{
    vector<int> jd = {6, 5, 4, 3, 2, 1};

    Solution s;
    cout << s.minDifficulty(jd, 4) << endl;
}