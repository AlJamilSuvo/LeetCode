#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        vector<int> inDegree(n, 0);
        vector<bool> haveTaken(n, false);
        vector<vector<int>> outDegree(n);
        for (int i = 0; i < relations.size(); i++)
        {
            int prev = relations[i][0] - 1;
            int next = relations[i][1] - 1;
            outDegree[prev].push_back(next);
            inDegree[next]++;
        }
        queue<vector<int>> q;
        int cCnt = 0;
        int sCnt = 0;

        vector<int> crs;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                crs.push_back(i);
                haveTaken[i] = true;
            }
        }
        q.push(crs);
        while (!q.empty())
        {
            sCnt += 1;
            vector<int> cur = q.front();
            q.pop();
            cCnt += cur.size();
            vector<int> nxt;
            for (auto cr : cur)
            {

                for (auto nextCr : outDegree[cr])
                {
                    if (!haveTaken[nextCr])
                    {
                        inDegree[nextCr]--;
                        if (inDegree[nextCr] == 0)
                        {
                            haveTaken[nextCr] = true;
                            nxt.push_back(nextCr);
                        }
                    }
                }
            }
            if (nxt.size() > 0)
                q.push(nxt);
        }
        if (cCnt == n)
            return sCnt;
        else return -1;
    }
};