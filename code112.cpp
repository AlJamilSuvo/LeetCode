#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool isLeafNode = root->left == nullptr && root->right == nullptr;
        if (isLeafNode)
        {
            return root->val == targetSum;
        }
        else
        {
            bool left = hasPathSum(root->left, targetSum - root->val);
            if (left)
                return left;
            bool right = hasPathSum(root->right, targetSum - root->val);
            return right;
        }
    }
};