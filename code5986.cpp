#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int m1 = targetSeconds / 60;
        int sec1 = targetSeconds % 60;
        int m2 = m1 - 1;
        int sec2 = sec1 + 60;
        int64_t c1 = INT_MAX;
        int64_t c2 = INT_MAX;

        if (m1 >= 0 && m1 <= 99 && sec1 >= 0 && sec1 <= 99)
            c1 = getCost(startAt, moveCost, pushCost, m1, sec1);

        if (m2 >= 0 && m2 <= 99 && sec1 >= 0 && sec2 <= 99)
            c2 = getCost(startAt, moveCost, pushCost, m2, sec2);

        return min(c1, c2);
    }

    int64_t getCost(int startAt, int moveCost, int pushCost, int min, int sec)
    {

        // cout << "time = " << min << " " << sec << endl;
        vector<int> digitis;
        if (min >= 10)
        {
            digitis.push_back(min / 10);
            digitis.push_back(min % 10);
        }
        else if (min > 0)
        {
            digitis.push_back(min);
        }

        if (min == 0 && sec < 10)
        {
            digitis.push_back(sec);
        }
        else
        {
            digitis.push_back(sec / 10);
            digitis.push_back(sec % 10);
        }

        int pos = startAt;
        int64_t cost = 0;
        for (int i = 0; i < digitis.size(); i++)
        {

            if (pos != digitis[i])
                cost += moveCost;
            cost += pushCost;
            // cout << "digit = " << digitis[i] << " " << cost << endl;
            pos = digitis[i];
        }

        return cost;
    }
};

int main()
{
    Solution s;
    cout << s.minCostSetTime(9, 100000, 1, 6039) << endl;
}

/// 7
// 220
// 479
// 6000

/* 9
100000
1
6039*/