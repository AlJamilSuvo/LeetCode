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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        bool check=p->val==q->val;
        if(check) check=isSameTree(p->left,q->left);
        if(check) check=isSameTree(p->right,q->right);
        return check;
    }
};