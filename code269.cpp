#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<char, int> inDegree;
    unordered_map<char, vector<char>> outDegree;
    map<pair<char, char>, bool> isEdgeFound;
    set<char> allChars;

public:
    string alienOrder(vector<string> &words)
    {

        int maxWordLen = 0;
        for (int i = 0; i < words.size(); i++)
        {
            maxWordLen = max(maxWordLen, (int)words[i].length());
            for (int j = 0; j < words[i].length(); j++)
            {
                allChars.insert(words[i][j]);
            }
        }

        int startIndex = 0;
        while (startIndex < maxWordLen)
        {

            string prefix = words[0].substr(0, startIndex);

            vector<char> order;
            for (int i = 0; i < words.size(); i++)
            {
                if (startIndex >= words[i].length())
                    continue;

                if (start_with(words[i], prefix))
                {
                    order.push_back(words[i][startIndex]);
                }
                else
                {
                    updateGraph(order);
                    order.clear();
                    prefix = words[i].substr(0, startIndex);
                    order.push_back(words[i][startIndex]);
                }
            }
            updateGraph(order);
            startIndex++;
        }

        queue<char> q;
        unordered_map<char, bool> isAdded;
        for (auto c : allChars)
        {
            cout << c << " " << inDegree[c] << endl;
            if (inDegree[c] == 0)
                q.push(c);
        }

        string result = "";
        while (!q.empty())
        {
            result += q.front();
            char c = q.front();
            q.pop();
            for (auto e : outDegree[c])
            {
                if (!isAdded[e])
                {
                    inDegree[e]--;
                    if (inDegree[e] == 0)
                    {
                        q.push(e);
                        isAdded[e] = true;
                    }
                }
            }
        }
        if (result.length() == allChars.size())
            return result;

        else
            return "";
    }

    void updateGraph(vector<char> &order)
    {
        if (order.size() < 2)
            return;

        cout << "order"
             << " ";
        for (auto c : order)
            cout << c << " ";
        cout << endl;

        for (int i = 0; i < order.size() - 1; i++)
        {
            for (int j = i + 1; j < order.size(); j++)
            {
                if (order[i] == order[j])
                    continue;
                if (isEdgeFound[{order[i], order[j]}])
                    continue;

                isEdgeFound[{order[i], order[j]}] = true;
                inDegree[order[j]]++;
                outDegree[order[i]].push_back(order[j]);
            }
        }
    }

    bool start_with(string src, string prefix)
    {
        for (int i = 0; i < prefix.size(); i++)
        {
            if (i >= src.length())
                return false;
            if (prefix[i] != src[i])
                return false;
        }
        return true;
    }
};

int main()
{
    vector<string> word = {"wrt", "wrf", "er", "ett", "rftt"};
    Solution s;
    s.alienOrder(word);
}
