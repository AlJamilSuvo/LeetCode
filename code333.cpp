#include <bits/stdc++.h>
#include "tree_node_util.hpp"
using namespace std;

class Result
{
public:
    int64_t lowest;
    int16_t highest;
    int size;
    bool isBST;
};

class Solution
{
    int finalResult = -1;

public:
    int largestBSTSubtree(TreeNode *root)
    {
        findLargestBST(root);
        return finalResult;
    }

    Result findLargestBST(TreeNode *node)
    {
        Result res;

        if (node == nullptr)
        {
            res.isBST = true;
            res.size = 0;
        }

        else if (node->left == nullptr && node->right == nullptr)
        {
            res.isBST = true;
            res.size = 1;
            res.lowest = node->val;
            res.highest = node->val;
        }
        else
        {
            bool isLeftOk = true;
            bool isRightOk = true;
            int leftSize = 0;
            int rightSize = 0;

            if (node->left != nullptr)
            {

                Result rl = findLargestBST(node->left);
                isLeftOk = rl.isBST && rl.highest < node->val;
                if (isLeftOk)
                    res.lowest = rl.lowest;
                leftSize = rl.size;
            }
            else
            {
                res.lowest = node->val;
            }

            if (node->right != nullptr)
            {

                Result rr = findLargestBST(node->right);
                isRightOk = rr.isBST && rr.lowest > node->val;
                if (isRightOk)
                    res.highest = rr.highest;
                rightSize = rr.size;
            }
            else
            {
                res.highest = node->val;
            }
            res.isBST = isLeftOk && isRightOk;
            if (res.isBST)
            {
                res.size = 1 + leftSize + rightSize;
            }
        }

        if (res.isBST && res.size > finalResult)
            finalResult = res.size;
        return res;
    }
};
