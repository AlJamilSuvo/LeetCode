#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> outDegree(numCourses);
        vector<bool> isAdded(numCourses, false);
        queue<int> Q;
        vector<int> result;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            inDegree[a]++;
            outDegree[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                Q.push(i);
                isAdded[i] = true;
            }
        }

        while (!Q.empty())
        {
            int c = Q.front();
            Q.pop();
            result.push_back(c);
            for (int i = 0; i < outDegree[c].size(); i++)
            {
                if (!isAdded[outDegree[c][i]])
                {
                    inDegree[outDegree[c][i]]--;
                    if (inDegree[outDegree[c][i]] == 0)
                    {
                        Q.push(outDegree[c][i]);
                        isAdded[outDegree[c][i]] = true;
                    }
                }
            }
        }

        if (result.size() == numCourses)
            return result;
        else
            return {};
    }
};