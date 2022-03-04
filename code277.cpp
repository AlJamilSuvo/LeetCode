#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b);

class Solution
{
public:
    int findCelebrity(int n)
    {
        vector<bool> isCelebrity(n, true);

        int possibleCelebrityCnt = n;
        while (possibleCelebrityCnt > 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (isCelebrity[i])
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (isCelebrity[j])
                        {
                            if (knows(j, i))
                            {
                                isCelebrity[j] = false;
                                possibleCelebrityCnt -= 1;
                            }
                            else
                            {
                                isCelebrity[i] = false;
                            }
                            if (knows(i, j))
                            {
                                isCelebrity[i] = false;
                            }
                            else if (isCelebrity[j])
                            {
                                isCelebrity[j] = false;
                                possibleCelebrityCnt -= 1;
                            }
                        }
                    }
                    if (!isCelebrity[i])
                        possibleCelebrityCnt -= 1;
                }
            }
        }
        if (possibleCelebrityCnt < 1)
            return -1;
        int possibleCelebrity;
        for (int i = 0; i < n; i++)
        {
            if (isCelebrity[i])
                possibleCelebrity = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == possibleCelebrity)
                continue;
            if (!knows(i, possibleCelebrity))
                return -1;
            if (knows(possibleCelebrity, i))
                return -1;
        }
        return possibleCelebrity;
    }
};