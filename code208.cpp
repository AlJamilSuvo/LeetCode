#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool end = false;
};

class Trie
{

private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->end = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->end;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return true;
    }
};