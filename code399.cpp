#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{
private:
    map<string, string> root;
    map<string, double> weight;
    map<string, int> rank;
    map<string, bool> known_variable;

    string find(const string &x)
    {
        if (root[x] == x)
            return x;
        return find(root[x]);
    }
    double getWeight(const string &x)
    {
        string r = find(x);
        if (r != root[x])
        {
            double w = weight[x] * getWeight(root[x]);
            root[x] = r;
            weight[x] = w;
        }
        return weight[x];
    }

public:
    DisjoinSet(const set<string> &all_variable)
    {
        for (auto veriable : all_variable)
        {
            root[veriable] = veriable;
            weight[veriable] = 1;
            rank[veriable] = 0;
            known_variable[veriable] = true;
        }
    }

    void make_union(const string &x, const string &y, double v)
    {
        string rootX = find(x);
        string rootY = find(y);
        double wX = getWeight(x);
        double wY = getWeight(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
                weight[rootY] = wX * v * (1 / wY);
            }
            else if (rank[rootY] > rank[rootX])
            {
                root[rootX] = rootY;
                weight[rootX] = wY * (1 / v) * (1 / wX);
            }
            else
            {
                root[rootY] = rootX;
                weight[rootY] = wX * v * (1 / wY);
                rank[rootX] += 1;
            }
        }
    }

    double get_result(const string &x, const string &y)
    {
        if (known_variable[x] && known_variable[y])
        {
            string rootX = find(x);
            string rootY = find(y);
            if (rootX == rootY)
            {
                double wX = getWeight(x);
                double wY = getWeight(y);
                return wY / wX;
            }
        }
        return -1;
    }
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        set<string> variables;
        for (int i = 0; i < equations.size(); i++)
        {
            variables.insert(equations[i][0]);
            variables.insert(equations[i][1]);
        }

        DisjoinSet ds(variables);
        for (int i = 0; i < equations.size(); i++)
        {
            ds.make_union(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); i++)
        {
            res.push_back(ds.get_result(queries[i][0], queries[i][1]));
        }
        return res;
    }
};