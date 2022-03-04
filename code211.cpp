#include <bits/stdc++.h>
using namespace std;

class TireNode
{
public:
    bool end = false;
    map<char, TireNode *> children;
};

class WordDictionary
{
private:
    TireNode *root = new TireNode();

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        TireNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i]] == nullptr)
            {
                node->children[word[i]] = new TireNode();
            }
            node = node->children[word[i]];
        }
        node->end = true;
    }

    bool search(string word)
    {
        queue<pair<TireNode *, int>> bfsQ;
        bfsQ.push({root, 0});
        while (!bfsQ.empty())
        {
            auto front = bfsQ.front();
            bfsQ.pop();
            TireNode *node = front.first;
            if(node==nullptr) return false;
            int i = front.second;
            if (i == word.size())
            {
                if (node->end)
                    return true;
                else
                    continue;
            }

            if (word[i] == '.')
            {
                for (const auto &[key, value] : node->children)
                {
                    bfsQ.push({value, i + 1});
                }
            }
            else
            {
                if (node->children[word[i]] == nullptr) continue;
                else
                    bfsQ.push({node->children[word[i]], i + 1});
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */