#include "tree_node_util.hpp"

class BSTIterator
{

    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root)
    {
        putTreeNodeOnStack(root);
    }

    void putTreeNodeOnStack(TreeNode *node)
    {
        if (node == nullptr)
            return;
        putTreeNodeOnStack(node->right);
        stk.push(node);
        putTreeNodeOnStack(node->left);
    }

    int next()
    {
        int val = stk.top()->val;
        stk.pop();
        return val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};
