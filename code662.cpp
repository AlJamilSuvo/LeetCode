#include "tree_node_util.hpp"
using namespace std;

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        vector<TreeNode *> que;
        vector<int64_t> nullQue;
        que.push_back(root);
        nullQue.push_back(0);
        int res = 1;
        while (!que.empty())
        {
            nullQue[0] = 0;
            vector<TreeNode *> nextQue;
            vector<int64_t> nextNullQue;
            int64_t nullCnt = 0;
            int len = 0;
            for (int i = 0; i < que.size(); i++)
            {
                len += nullQue[i];
                len += 1;
                nullCnt += nullQue[i] * 2;
                if (que[i]->left != nullptr)
                {
                    nextNullQue.push_back(nullCnt);
                    nextQue.push_back(que[i]->left);
                    nullCnt = 0;
                }
                else
                {
                    nullCnt += 1;
                }
                if (que[i]->right != nullptr)
                {
                    nextNullQue.push_back(nullCnt);
                    nextQue.push_back(que[i]->right);
                    nullCnt = 0;
                }
                else
                {
                    nullCnt += 1;
                }
            }

            res = max(res, len);
            que = nextQue;
            nullQue = nextNullQue;
        }
        return res;
    }
};