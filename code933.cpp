#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
    queue<int> que;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        que.push(t);
        while (t- que.front() > 3000)
            que.pop();
        return que.size();
    }
};
