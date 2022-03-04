#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        map<string, int64_t> cntMap;
        set<string> domains;
        for (int i = 0; i < cpdomains.size(); i++)
        {
            int pos = 0;
            while (cpdomains[i][pos] != ' ')
            {
                pos++;
            }
            cout << cpdomains[i] << endl;
            int64_t cnt = stoi(cpdomains[i].substr(0, pos + 1));
            cout << cnt << endl;
            string domain = cpdomains[i].substr(pos + 1, cpdomains[i].length() - pos - 1);
            pos = 0;
            cntMap[domain] += cnt;
            domains.insert(domain);
            cout << domain << endl;
            while (pos < domain.length())
            {
                if (domain[pos] == '.')
                {
                    domain = domain.substr(pos + 1, domain.size() - pos - 1);
                    cntMap[domain] += cnt;
                    cout << domain << endl;
                    domains.insert(domain);
                    pos = 0;
                }
                else
                    pos++;
            }
        }
        vector<string> res;
        for (auto doamin : domains)
        {
            res.push_back(to_string(cntMap[doamin]) + " " + doamin);
        }
        return res;
    }
};