#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> root;
    vector<int> rank;
    map<int, priority_queue<char, vector<char>, greater<char>>> pq;

public:
    DisjointSet(int sz) : root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (root[x] != x)
        {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void make_union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootY] > rank[rootX])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    void insert_char(int index, char c)
    {
        int r = find(index);
        pq[r].push(c);
    }
    char get_char(int index)
    {
        int r = find(index);
        char c = pq[r].top();
        pq[r].pop();
        return c;
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        DisjointSet ds(s.length());
        for (int i = 0; i < pairs.size(); i++)
        {
            ds.make_union(pairs[i][0], pairs[i][1]);
        }
        for (int i = 0; i < s.length(); i++)
        {
            ds.insert_char(i, s[i]);
        }
        for(int i=0;i<s.length();i++){
            s[i] = ds.get_char(i);
        }
        return s;
    }
};