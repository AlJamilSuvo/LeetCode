#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {

        if (start == end)
            return 0;
        map<string, int> found;
        map<string, int> distance;
        queue<string> que;
        que.push(start);
        found[start] = true;
        distance[start] = 0;

        while (!que.empty())
        {
            string current = que.front();
            que.pop();
            int d = distance[current];
            // int diff = get_difference(current, end);
            // if (diff <= 1)
            // {
            //     return d + diff;
            // }

            for (auto b : bank)
            {
                if (found[b])
                    continue;
                int diff = get_difference(current, b);
                if (diff <= 1)
                {
                    if (b == end)
                        return d + diff;

                    found[b] = true;
                    distance[b] = d + diff;
                    que.push(b);
                }
            }
        }
        return -1;
    }

    int get_difference(string &s1, string &s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                diff++;
        }
        return diff;
    }
};

int main()
{
    vector<string> s1 = {"AACCGGTA"};
    vector<string> s2 = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    vector<string> s3 = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    Solution s;
    cout << s.minMutation("AACCGGTT", "AACCGGTA", s1) << endl;
    cout << s.minMutation("AACCGGTT", "AAACGGTA", s2) << endl;
    cout << s.minMutation("AAAAACCC", "AACCCCCC", s3) << endl;
    cout << s.minMutation("AAAAACCC", "GGGGGGGG", s3) << endl;
}