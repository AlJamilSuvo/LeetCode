#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        bool isOnGoingWord = false;
        string currWord = "";
        stack<string> wordStack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (isOnGoingWord)
                {
                    wordStack.push(currWord);
                    currWord = "";
                }
                isOnGoingWord = false;
            }
            else
            {
                isOnGoingWord = true;
                currWord += s[i];
            }
        }
        if (isOnGoingWord)
        {
            wordStack.push(currWord);
            currWord = "";
        }
        string result = "";
        while (!wordStack.empty())
        {
            string word = wordStack.top();
            wordStack.pop();
            result += word;

            if (!wordStack.empty())
                result += " ";
        }
        return result;
    }
};