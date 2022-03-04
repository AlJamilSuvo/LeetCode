#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int idx = 0;
        vector<string> result;
        while (idx < words.size())
        {
            int lineLength = 0;
            int wordPicked = 0;
            for (int i = 0; i < words.size() - idx; i++)
            {
                if (lineLength + words[idx + i].length() + i <= maxWidth)
                {
                    lineLength += words[idx + i].length();
                    wordPicked += 1;
                }
                else
                    break;
            }
            if (idx + wordPicked == words.size() || wordPicked == 1)
            {
                string res = words[idx];
                for (int i = 1; i < wordPicked; i++)
                {
                    res += " " + words[idx + i];
                }
                int spaceCnt = maxWidth - res.length();
                for (int i = 0; i < spaceCnt; i++)
                {
                    res = res + " ";
                }
                // cout << res << " " << res.length() << endl;
                result.push_back(res);
            }
            else
            {
                string res = "";
                int spaceCnt = maxWidth - lineLength;
                int spaceBetween = spaceCnt / (wordPicked - 1);
                int mod = spaceCnt % (wordPicked - 1);
                for (int i = 0; i < wordPicked - 1; i++)
                {
                    res += words[idx + i];
                    for (int j = 0; j < spaceBetween; j++)
                        res += " ";
                    if (i < mod)
                        res += " ";
                }
                res += words[idx + wordPicked - 1];
                // cout << res << " " << res.length() << endl;
                result.push_back(res);
            }
            idx += wordPicked;
        }

        return result;
    }
};