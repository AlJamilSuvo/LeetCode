#include <bits/stdc++.h>
using namespace std;

//top down
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         vector<vector<int>> dp(prices.size(), vector(2, -1));
//         return maxProfit(prices, 0, 0, dp);
//     }

//     int maxProfit(vector<int> &prices, int day, int have_share, vector<vector<int>> &dp)
//     {
//         if (day >= prices.size())
//         {
//             return 0;
//         }

//         if (dp[day][have_share] != -1)
//             return dp[day][have_share];

//         if (have_share)
//         {
//             int sellNow = prices[day];
//             int sellLeter = maxProfit(prices, day + 1, have_share, dp);
//             dp[day][have_share] = max(sellNow, sellLeter);
//         }
//         else
//         {
//             int buyNow = maxProfit(prices, day + 1, 1, dp) - prices[day];
//             int buyLetter = maxProfit(prices, day + 1, 0, dp);
//             dp[day][have_share] = max(buyNow, buyLetter);
//         }
//         // cout << "calculating d=" << day << " h=" << have_share << " result = " << dp[day][have_share] << endl;
//         return dp[day][have_share];
//     }
// };

//top down
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp[prices.size() + 1][2];
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;

        for (int day = prices.size() - 1; day >= 0; day--)
        {
            dp[day][0] = max(-prices[day] + dp[day + 1][1], dp[day + 1][0]);
            dp[day][1] = max(prices[day], dp[day + 1][1]);
        }
        return dp[0][0];
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int not_having = 0;
        int having = 0;

        for (int day = prices.size() - 1; day >= 0; day--)
        {
            not_having = max(-prices[day] + having, not_having);
            having = max(prices[day], having);
        }
        return not_having;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
}