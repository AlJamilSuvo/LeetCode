#include "n_arr_util.hpp"
#include "tree_node_util.hpp"

class Codec
{
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode *encode(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *bTreeRoot = new TreeNode(root->val);
        TreeNode *prevNode = nullptr;
        for (int i = 0; i < root->children.size(); i++)
        {
            TreeNode *newNode = encode(root->children[i]);
            if (i == 0)
            {
                bTreeRoot->right = newNode;
            }
            else
            {
                prevNode->left = newNode;
            }
            prevNode = newNode;
        }

        return bTreeRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        map<TreeNode *, Node *> bnMap;
        Node *nArrayRoot = new Node(root->val);
        bnMap[root] = nArrayRoot;
        queue<TreeNode *> bfsQ;
        bfsQ.push(root);
        while (!bfsQ.empty())
        {
            TreeNode *btNode = bfsQ.front();
            bfsQ.pop();
            Node *nArr = bnMap[btNode];
            TreeNode *childNode = btNode->right;
            while (childNode != nullptr)
            {
                Node *nArrChild = new Node(childNode->val);
                bnMap[childNode] = nArrChild;
                nArr->children.push_back(nArrChild);
                bfsQ.push(childNode);
                childNode = childNode->left;
            }
        }

        return nArrayRoot;
    }
};