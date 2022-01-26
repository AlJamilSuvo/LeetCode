#include "tree_node_util.hpp"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int val = preorder[0];
        int len = preorder.size();
        TreeNode *node = new TreeNode(val);
        if (len == 1)
            return node;

        int leftTreeSize = 0;
        int rightTreeSize = 0;

        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == val)
                break;
            leftTreeSize += 1;
        }

        rightTreeSize = len - leftTreeSize - 1;

        if (leftTreeSize > 0)
        {
            vector<int> leftPre, leftIn;
            for (int i = 0; i < leftTreeSize; i++)
            {
                leftPre.push_back(preorder[1 + i]);
                leftIn.push_back(inorder[i]);
            }
            node->left = buildTree(leftPre, leftIn);
        }

        if (rightTreeSize > 0)
        {
            vector<int> rightPre, rightIn;
            for (int i = 0; i < rightTreeSize; i++)
            {
                rightPre.push_back(preorder[1 + leftTreeSize + i]);
                rightIn.push_back(inorder[1 + leftTreeSize + i]);
            }
            node->right = buildTree(rightPre, rightIn);
        }
        return node;
    }
};