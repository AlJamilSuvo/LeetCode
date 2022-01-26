#include "tree_node_util.hpp"

class Solution
{
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return isValidSequence(root, arr, 0);
    }

    bool isValidSequence(TreeNode *node, vector<int> &arr, int arr_index)
    {
        if (node == nullptr && arr_index == arr.size())
            return true;
        if (node == nullptr && arr_index != arr.size())
            return false;
        if (node != nullptr && arr_index == arr.size())
            return false;

        if (node->val != arr[arr_index])
            return false;

        bool left = false;
        bool right = false;
        bool is_leaf_node = node->left == nullptr && node->right == nullptr;
        if (is_leaf_node)
        {
            if (arr_index == arr.size() - 1)
                return true;
        }

        if (node->left != nullptr)
            left = isValidSequence(node->left, arr, arr_index + 1);
        if (node->right != nullptr)
            right = isValidSequence(node->right, arr, arr_index + 1);

        return left || right;
    }
};

/*
[8,3,null,2,1,5,4]
[8]
*/