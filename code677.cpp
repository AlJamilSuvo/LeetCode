#include <bits/stdc++.h>
using namespace std;

class TriNode
{
public:
    int sum = 0;
    TriNode *children[26];
    int endSum = 0;
};

class MapSum
{
private:
    TriNode *root;

public:
    MapSum()
    {
        root = new TriNode();
    }

    void insert(string key, int val)
    {
        int adjVal = val - oldSum(key);
        TriNode *node = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new TriNode();
            }
            node = node->children[index];
            node->sum += adjVal;
        }
        node->endSum = val;
    }

    int sum(string prefix)
    {
        TriNode *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (node->children[index] == nullptr)
            {
                return 0;
            }
            node = node->children[index];
        }
        return node->sum;
    }

private:
    int oldSum(string key)
    {
        TriNode *node = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (node->children[index] == nullptr)
            {
                return 0;
            }
            node = node->children[index];
        }
        return node->endSum;
    }
};
