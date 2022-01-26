#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int move = 0;
        while (maxDoubles > 0)
        {
            if (target % 2 == 1)
                move += 2;
            else
                move++;
            target = target / 2;
            if (target == 1)
                return move;
            maxDoubles--;
        }
        move += target - 1;
        return move;
    }
};

int main()
{
    Solution s;
    cout << s.minMoves(5, 0) << endl;
    cout << s.minMoves(19, 2) << endl;
    cout << s.minMoves(2, 4) << endl;
}