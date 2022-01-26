#include "tree_node_util.hpp"

class Codec
{
public:
    // Encodes a tree to a single string.

    int treeHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        return 1 + max(treeHeight(node->left), treeHeight(node->right));
    }

    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        queue<TreeNode *> Q;
        Q.push(root);
        string result = "";
        int h = treeHeight(root);
        map<TreeNode *, int> distance;

        distance[root] = 1;
        int currD = 1;

        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();
            if (node != nullptr)
            {
                currD = max(currD, distance[node]);
                result += to_string(node->val);
                if (node->left != nullptr)
                {
                    distance[node->left] = currD + 1;
                }
                if (node->right != nullptr)
                {
                    distance[node->right] = currD + 1;
                }
                Q.push(node->left);
                Q.push(node->right);
            }
            result += ",";
        }
        int cut = result.length() - 1;
        for (cut = result.length() - 1; cut >= 0; cut--)
        {
            if (result[cut] != ',')
                break;
        }
        result = result.substr(0, cut + 1);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return nullptr;
        string cur = "";
        queue<TreeNode *> Q;
        TreeNode *root;
        for (int i = 0; i <= data.length(); i++)
        {
            if (i == data.length() || data[i] == ',')
            {
                TreeNode *node = nullptr;
                if (cur.length() > 0)
                {
                    int val = stoi(cur);
                    node = new TreeNode(val);
                    cur = "";
                }

                if (Q.empty())
                {
                    root = node;
                }
                else
                {
                    TreeNode *parent = Q.front();
                    Q.pop();

                    if (parent != nullptr)
                    {
                        if (Q.front() == parent)
                            parent->left = node;
                        else
                            parent->right = node;
                    }
                }

                if(node!=nullptr){
                    Q.push(node);
                    Q.push(node);
                }
            }
            else
                cur += data[i];
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));