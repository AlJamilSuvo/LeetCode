#include "tree_node_util.hpp"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int len = postorder.size();
        int val = postorder[len - 1];
        TreeNode *node = new TreeNode(val);
        if (len == 1)
            return node;

        int leftTreeSize = 0;
        for (int i = 0; i < len; i++)
        {
            if (inorder[i] == val)
                break;
            leftTreeSize += 1;
        }

        int rightTreeSize = len - leftTreeSize - 1;

        if (leftTreeSize > 0)
        {
            vector<int> left_inorder;
            vector<int> left_postorder;
            for (int i = 0; i < leftTreeSize; i++)
            {
                left_inorder.push_back(inorder[i]);
                left_postorder.push_back(postorder[i]);
            }
            node->left = buildTree(left_inorder, left_postorder);
        }
        if (rightTreeSize > 0)
        {
            vector<int> right_inorder;
            vector<int> right_postorder;
            for (int i = 0; i < rightTreeSize; i++)
            {
                right_inorder.push_back(inorder[leftTreeSize + 1 + i]);
                right_postorder.push_back(postorder[leftTreeSize + i]);
            }
            node->right = buildTree(right_inorder, right_postorder);
        }

        return node;
    }
};