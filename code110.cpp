#include "list_node_util.hpp"

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
    bool isBalanced(TreeNode *root)
    {
        int height;
        bool balace;
        getHeightAndCheckBalance(root, height, balace);
        return balace;
    }
    void getHeightAndCheckBalance(TreeNode *node, int &height, bool &balaced)
    {
        if (node == nullptr)
        {
            height = 0;
            balaced = true;
            return;
        }
        int leftHeight, rightHeight;
        bool leftBalace, rightBalace;
        getHeightAndCheckBalance(node->left, leftHeight, leftBalace);
        getHeightAndCheckBalance(node->right, rightHeight, rightBalace);
        int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
        height = maxHeight + 1;
        balaced = leftBalace && rightBalace && abs(leftHeight - rightHeight) <= 1;
    }
};