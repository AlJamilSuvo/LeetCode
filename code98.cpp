/**
 * Definition for a binary tree node.*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stk;
        map<TreeNode *,bool> isVisited;
        int last_inorder_traversal_value=-1<31;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode * cur=stk.top();
            stk.pop();
            if(cur==NULL) continue;
            if(isVisited[cur]){
                if(last_inorder_traversal_value<cur->val) last_inorder_traversal_value=cur->val;
                else return false;
            }
            else{
                isVisited[cur]=true;
                stk.push(cur->right);
                stk.push(cur);
                stk.push(cur->left);
            }

        }
        return true;
        

        
    }
};