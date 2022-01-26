#include "n_arr_util.hpp"

class Solution
{
public:
    vector<int> postorder(Node *root)
    {

        vector<int> res;
        if (root = nullptr)
            return res;
        stack<Node *> s;
        queue<Node *> q;
        s.push(root);
        while (!s.empty())
        {
            Node * node = s.top();
            s.pop();
            q.push()
        }
    }
};