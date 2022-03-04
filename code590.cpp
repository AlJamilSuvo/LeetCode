#include "n_arr_util.hpp"

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
    
    void postorder(Node *node, vector<int>& res){
        if(node==nullptr) return;
        for(int i=0;i<node->children.size();i++){
            postorder(node->children[i], res);
        }
        res.push_back(node->val);
    }
};