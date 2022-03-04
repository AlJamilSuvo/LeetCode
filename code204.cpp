#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {

        if (n < 2)
            return 0;
        vector<bool> isPrime(n + 1, true);
        int cnt = 0;
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                cnt += 1;
                for (int j = i + i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return cnt;
    }
};