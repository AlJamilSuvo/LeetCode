#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2)
    {
        map<string, set<string>> adjList;
        for (int i = 0; i < wordsDict.size(); i++)
        {
            if (i > 0)
            {
                adjList[wordsDict[i]].insert(wordsDict[i - 1]);
            }
            if (i != wordsDict.size() - 1)
            {
                adjList[wordsDict[i]].insert(wordsDict[i + 1]);
            }
        }
        unordered_map<string, int> distance;
        unordered_map<string, bool> seen;
        queue<string> bfsQ;
        distance[word1] = 0;
        seen[word1] = true;
        bfsQ.push(word1);
        while (!bfsQ.empty())
        {
            string word = bfsQ.front();
            bfsQ.pop();
            int d = distance[word];
            for (auto adj : adjList[word])
            {
                if (!seen[adj])
                {
                    if (adj == word2)
                        return d + 1;
                    distance[adj] = d + 1;
                    seen[adj] = true;
                    bfsQ.push(adj);
                }
            }
        }
        return distance[word2];
    }
};