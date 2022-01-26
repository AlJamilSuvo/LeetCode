#include "tree_node_util.hpp"

class Solution
{
public:
    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target)
    {
        if (root1 == nullptr || root2 == nullptr)
            return false;

        int sum = root1->val + root2->val;
        if (sum == target)
            return true;
        if (target < sum)
        {
            return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1, root2->left, target);
        }
        else
            return twoSumBSTs(root1->right, root2, target) || twoSumBSTs(root1, root2->right, target);
    }
};


int main(){


}