#include <bits/stdc++.h>
using namespace std;

class Comparator
{

public:
    bool operator()(const string &s1, const string &s2)
    {
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i])
            i++;
        if (i == s1.length())
            return s1[i - 1] < s2[0];
        if (i == s2.length())
            return s1[0] < s2[i - 1];
        return s1[i] < s2[i];
    }
};

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        priority_queue<string, vector<string>, Comparator> Q;
        for (int i = 0; i < nums.size(); i++)
        {
            Q.push(to_string(nums[i]));
        }
        string result = "";

        while (!Q.empty())
        {
            result += Q.top();
            Q.pop();
        }
        return result;
    }
};
