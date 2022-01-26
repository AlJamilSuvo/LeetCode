#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int sCount = 0;
        int64_t pCount = 0;
        int64_t posCount = 0;
        for (int i = 0; i < corridor.length(); i++)
        {

            if (corridor[i] == 'S')
            {
                if (sCount == 2)
                {
                    sCount = 1;
                    if (pCount != 0)
                    {
                        posCount += pCount + 1;
                        cout << pCount << posCount << endl;
                        pCount = 0;
                    }
                }
                else
                    sCount++;
            }
            if (corridor[i] == 'P' && sCount == 2)
            {
                pCount += 1;
            }
        }

        if (sCount == 2)
            return posCount;
        else
            return 0;
    }
};

int main()
{
    Solution s;
    cout << s.numberOfWays("SSPPSPS") << endl;
}