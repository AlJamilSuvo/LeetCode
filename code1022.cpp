#include <bits/stdc++.h>
#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    int sumRootToLeaf(TreeNode *root)
    {
        int totlaSum = 0;
        sumRootToLeafNode(root, 0, totlaSum);
        return totlaSum;
    }

    void sumRootToLeafNode(TreeNode *node, int upperSum, int &totalSum)
    {
        if (node == nullptr)
        {
            totalSum += upperSum;
            return;
        }
        upperSum = upperSum * 2 + node->val;
        if(node->left==nullptr && node->right==nullptr){
            totalSum+=upperSum;
            return;
        }
        sumRootToLeafNode(node->left, upperSum, totalSum);
        sumRootToLeafNode(node->right, upperSum, totalSum);
    }
};