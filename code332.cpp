#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, vector<string>> adjList;
        map<string, vector<bool>> usedPath;
        set<string> sources;
        for (int i = 0; i < tickets.size(); i++)
        {
            adjList[tickets[i][0]].push_back(tickets[i][1]);
            sources.insert(tickets[i][0]);
            usedPath[tickets[i][0]].push_back(false);
        }
        for (auto src : sources)
        {
            sort(adjList[src].begin(),adjList[src].end());
        }

        map<string, bool> addedPath;
        vector<string> currentPath;
        int maxPathLength = 0;
        vector<vector<string>> allPaths;
        findItinerary(adjList, usedPath, "JFK", currentPath, allPaths, maxPathLength, tickets.size() + 1);
        // sort(allPaths.begin(), allPaths.end());
        return allPaths[0];
    }

    void findItinerary(map<string, vector<string>> &adjList,
                       map<string, vector<bool>> usedPath, string src,
                       vector<string> currentPath,
                       vector<vector<string>> &allPaths,
                       int &maxPathLength,
                       int expectedPathLength)
    {
        currentPath.push_back(src);
        bool inNewPathFound = false;
        int i = 0;
        for (auto des : adjList[src])
        {
            if (!usedPath[src][i])
            {
                usedPath[src][i] = true;
                findItinerary(adjList, usedPath, des, currentPath, allPaths, maxPathLength, expectedPathLength);
                if (maxPathLength == expectedPathLength)
                    return;
                usedPath[src][i] = false;
                inNewPathFound = true;
            }
            i += 1;
        }

        if (!inNewPathFound)
        {
            if (currentPath.size() > maxPathLength)
            {
                allPaths.clear();
                allPaths.push_back(currentPath);
                maxPathLength = currentPath.size();
            }
            if (currentPath.size() == maxPathLength)
            {
                allPaths.push_back(currentPath);
            }
        }
    }
};

///[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]