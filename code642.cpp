#include <bits/stdc++.h>
using namespace std;

class TriNode
{
public:
    int f = 0;
    bool end = false;
    map<char, TriNode *> children;
};

class Result
{
public:
    string result;
    int f;
};
class ResultCompare
{
public:
    bool operator()(const Result &r1, const Result &r2)
    {
        if (r1.f == r2.f)
        {
            return r1.result > r2.result;
        }

        return r1.f < r2.f;
    }
};

class AutocompleteSystem
{
    TriNode *root = new TriNode();
    string curString;

    void insert(string sentence, int f = 1)
    {
        TriNode *node = root;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (node->children[sentence[i]] == nullptr)
            {
                node->children[sentence[i]] = new TriNode();
            }
            node = node->children[sentence[i]];
        }
        node->f += f;
        node->end = true;
    }

    priority_queue<Result, vector<Result>, ResultCompare> getSuggestion(string key)
    {
        priority_queue<Result, vector<Result>, ResultCompare> res;
        TriNode *node = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (node->children[key[i]] == nullptr)
                return res;
            node = node->children[key[i]];
        }
        queue<pair<TriNode *, string>> bfsQ;
        bfsQ.push({node, key});
        while (!bfsQ.empty())
        {
            auto fnt = bfsQ.front();
            bfsQ.pop();
            TriNode *cur = fnt.first;
            string curStr = fnt.second;
            if (cur->end)
            {
                Result r;
                r.f = cur->f;
                r.result = curStr;
                res.push(r);
            }
            for (const auto &[key, value] : cur->children)
            {
                bfsQ.push({value, curStr + key});
            }
        }
        return res;
    }

public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        for (int i = 0; i < sentences.size(); i++)
        {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c)
    {
        if (c == '#')
        {
            insert(curString);
            curString = "";
            return {};
        }
        else
        {
            vector<string> finalRes;
            curString = curString + c;
            auto res = getSuggestion(curString);
            for (int i = 0; i < 3; i++)
            {
                if (res.empty())
                    break;
                Result r = res.top();
                res.pop();
                finalRes.push_back(r.result);
            }
            return finalRes;
        }
    }
};

int main()
{

    priority_queue<Result, vector<Result>, ResultCompare> q;
}