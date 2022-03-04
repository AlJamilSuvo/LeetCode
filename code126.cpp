#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
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
        queue<vector<string>> bfsQ;
        vector<vector<string>> res;
        int minD = INT_MAX;
        bfsQ.push({beginWord});

        while (!bfsQ.empty())
        {
            vector<string> cur = bfsQ.front();
            map<string, bool> found;
            for (int i = 0; i < cur.size(); i++)
            {
                found[cur[i]] = true;
            }
            string last = cur[cur.size() - 1];
            bfsQ.pop();
            int d = cur.size();
            if (d > minD)
                break;
            if (last == endWord)
            {
                if (d < minD)
                    res.clear();
                res.push_back(cur);
                minD = d;
            }

            for (auto adjStr : adjList[last])
            {
                if (found[adjStr])
                    continue;
                found[adjStr] = true;
                cur.push_back(adjStr);
                bfsQ.push(cur);
                cur.pop_back();
            }
        }
        return res;
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