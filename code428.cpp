#include "n_arr_util.hpp"

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (root == nullptr)
            return "";
        string valStr = to_string(root->val);
        string childStr = "";
        if (root->children.size() == 0)
            return valStr;
        for (int i = 0; i < root->children.size(); i++)
        {
            childStr += serialize(root->children[i]);
            if (i != root->children.size() - 1)
                childStr += ",";
        }
        cout << "(" + valStr + "," + childStr + ")" << endl;
        return "(" + valStr + "," + childStr + ")";
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data.length() == 0)
            return nullptr;
        if (data[0] == '(')
        {
            stack<char> stk;
            string cur = "";
            Node *root = nullptr;
            for (int i = 1; i < data.size(); i++)
            {
                if ((data[i] == ',' || data[i] == ')') && stk.empty())
                {
                    if (root == nullptr)
                    {
                        root = new Node(stoi(cur));
                    }
                    else
                    {
                        root->children.push_back(deserialize(cur));
                    }
                    cur = "";
                }
                else
                {
                    cur += data[i];
                    if (data[i] == '(')
                        stk.push('(');
                    if (data[i] == ')')
                        stk.pop();
                }
            }
            return root;
        }
        else
        {

            int val = stoi(data);
            Node *node = new Node(val);
            return node;
        }
    }
};