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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        int height;
        if (root->left == nullptr && root->right != nullptr)
            height = right;
        else if (root->right == nullptr && root->left != nullptr)
            height = left;
        else height = min(left,right);

        return height + 1;
    }
};