#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> allResult;
        map<string, bool> isGenerated;
        vector<string> res;
        for (int i = 0; i < s.length(); i++)
        {
            
        }
    }

    string to_key_string(vector<string> strArr)
    {
        string res = "";
        for (int i = 0; i < strArr.size(); i++)
        {
            res += strArr[i];
            if (i != strArr.size() - 1)
                res += ",";
        }
        return res;
    }
};
