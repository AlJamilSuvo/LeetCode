#include <bits/stdc++.h>
using namespace std;

class TriNode
{
public:
    bool end = false;
    TriNode *children[26];
};

class Solution
{
private:
    TriNode *root = new TriNode();

    void insert(string key)
    {
        TriNode *node = root;
        for (int i = 0; i < key.length(); i++)
        {
            int idx = key[i] - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TriNode();
            node = node->children[idx];
        }
        node->end = true;
    }

    string getRootWord(string word)
    {
        TriNode *node = root;
        string rootWord = "";
        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (node->children[idx] == nullptr)
                return word;
            rootWord = rootWord + word[i];
            node = node->children[idx];
            if (node->end)
                return rootWord;
        }
        return word;
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (int i = 0; i < dictionary.size(); i++)
        {
            insert(dictionary[i]);
        }
        string result = "";
        string currWord = "";
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                result += getRootWord(currWord) + " ";
                currWord = "";
            }
            else
                currWord += sentence[i];
        }

        result += getRootWord(currWord);
        return result;
    }
};