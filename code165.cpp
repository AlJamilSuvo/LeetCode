#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1;
        vector<int> v2;
        getVerCodeArr(version1, v1);
        getVerCodeArr(version2, v2);
        int m = max(v1.size(), v2.size());
        for (int i = 0; i < m; i++)
        {
            int vc1 = 0;
            int vc2 = 0;
            if (i < v1.size())
                vc1 = v1[i];
            if (i < v2.size())
                vc2 = v2[i];
            if (vc1 < vc2)
                return -1;
            if(vc1>vc2) return 1;
        }
        return 0;
    }

    void getVerCodeArr(string &v, vector<int> &vArr)
    {
        string cur = "";
        for (int i = 0; i < v.length(); i++)
        {
            if (v[i] == '.')
            {
                if (cur == "")
                    cur = "0";
                vArr.push_back(stoi(cur));
                cur = "";
            }
            else
                cur += v[i];
        }
        if (cur == "")
            cur = "0";
        vArr.push_back(stoi(cur));
    }
};

int main()
{
    Solution s;
    cout << s.compareVersion("0.1", "1.1") << endl;
}