#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    bool isOperator = false;
    int number = 0;
    char op = ' ';
};

class Solution
{
public:
    int calculate(string s)
    {
        queue<Item> outputQue;
        stack<char> optStk;
        string cur;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;

            if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+')
            {
                if (cur != "")
                {
                    int num = stoi(cur);
                    Item item;
                    item.isOperator = false;
                    item.number = num;
                    outputQue.push(item);
                }
                cur = "";
                char op1 = s[i];
                while (!optStk.empty() && !isGreateOpt(op1, optStk.top()))
                {
                    char op2 = optStk.top();
                    Item item;
                    item.isOperator = true;
                    item.op = op2;
                    optStk.pop();
    
                }
            }
        }
    }

    bool isGreateOpt(char op1, char op2)
    {
        map<char, int> rank;
        rank['/'] = 4;
        rank['*'] = 3;
        rank['-'] = 2;
        rank['+'] = 1;

        return rank[op1] >= rank[op2];
    }
};