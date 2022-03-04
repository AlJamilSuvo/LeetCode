#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        priority_queue<char> q;
        for (int i = 0; i < s.length(); i++)
        {
            q.push(s[i]);
        }
        int cnt = 0;
        char lastChr = '\0';
        string res = "";
        while (!q.empty())
        {
            if (lastChr == q.top() && cnt == repeatLimit)
            {
                int c = 0;
                while (lastChr == q.top() && !q.empty())
                {
                    c += 1;
                    q.pop();
                }
                cout << lastChr << " " << q.size() << " " << c << endl;
                if (q.empty())
                    return res;
                char nextChar = q.top();
                cout << lastChr << " " << nextChar << q.size() << " " << c << endl;
                res += nextChar;
                q.pop();

                while (c > 0)
                {
                    int add = min(c, repeatLimit);
                    int remaining = c - add;
                    for (int i = 0; i < add; i++)
                    {
                        res += lastChr;
                    }
                    if (q.empty())
                        return res;
                    res += q.top();
                    nextChar = q.top();
                    cnt = 1;
                    q.pop();
                    c = remaining;
                }
                lastChr = nextChar;
            }
            else
            {
                res += q.top();
                if (lastChr == q.top())
                {
                    cnt += 1;
                }
                else
                {
                    cnt = 1;
                }
                lastChr = q.top();
                q.pop();
            }
        }
        return res;
    }
};

/*

"robnsdvpuxbapuqgopqvxdrchivlifeepy"
2

"yxxvvuvusrrqqppopponliihgfeeddcbba"

*/