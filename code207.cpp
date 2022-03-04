#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> outEdges(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
            outEdges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<bool> isTaken(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                isTaken[i] = true;
            }
        }
        int takenCnt = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            takenCnt += 1;
            for (auto e : outEdges[top])
            {
                if (!isTaken[e])
                {
                    inDegree[e]--;
                    if (inDegree[e] == 0)
                    {
                        q.push(e);
                        isTaken[e] = true;
                    }
                }
            }
        }
        return takenCnt == numCourses;
    }
};