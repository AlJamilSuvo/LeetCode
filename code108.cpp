#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }

    TreeNode * sortedArrayToBST(vector<int>& nums, int left, int right){
        if(left>right) return nullptr;
        if(left == right) return new TreeNode(nums[left]);
        int mid = (left+right)/2;
        TreeNode * treeNode = new TreeNode(nums[mid]);
        treeNode->left = sortedArrayToBST(nums,left,mid-1);    
        treeNode->right = sortedArrayToBST(nums,mid+1,right);
        return treeNode;
    }
};