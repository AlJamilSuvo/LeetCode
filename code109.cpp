#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

    ListNode *  head = nullptr;
    int getLinkedListSize(ListNode * head) {
        int size = 0;
        ListNode * pnt = head;
        while (pnt !=nullptr)
        {
            pnt = pnt->next;
            size+=1;
        }
        return size;
    }

    TreeNode * convertLLToBST(int left,int right) {
        if(left>right) return nullptr;
        int mid = (left+right)/2;
        TreeNode * leftTree = convertLLToBST(left,mid-1);
        TreeNode * root = new TreeNode(head->val);
        head = head->next;
        TreeNode * rightTree = convertLLToBST(mid+1,right);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        int size = getLinkedListSize(head);
        if(size == 0) return nullptr;
        this->head =head;
        return convertLLToBST(0,size-1);   
    }
};