#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> adjList;
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size() - 1; i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if (isAdj(wordList[i], wordList[j]))
                {
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        map<string, int> distance;
        map<string, bool> found;
        queue<string> bfsQ;
        bfsQ.push(beginWord);
        distance[beginWord] = 1;
        found[beginWord] = true;
        while (!bfsQ.empty())
        {
            string cur = bfsQ.front();
            bfsQ.pop();
            int d = distance[cur];
            for (int i = 0; i < adjList[cur].size(); i++)
            {
                if (found[adjList[cur][i]])
                    continue;
                distance[adjList[cur][i]] = d + 1;
                if (adjList[cur][i] == endWord)
                    return d + 1;
                found[adjList[cur][i]] = true;
                bfsQ.push(adjList[cur][i]);
            }
        }
        return 0;
    }

    bool isAdj(const string &s1, const string &s2)
    {
        int diffCount = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                diffCount++;
            if (diffCount > 1)
                return false;
        }
        return diffCount == 1;
    }
};