#include <bits/stdc++.h>
#include "list_node_util.hpp"
using namespace std;

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *resHead = nullptr;
        ListNode *node = head;
        ListNode *resCur = nullptr;
        int sum = 0;
        while (node != nullptr)
        {
            if (node->val == 0)
            {
                if (sum != 0)
                {
                    ListNode *n1 = new ListNode(sum);
                    if (resCur == nullptr)
                    {
                        resHead = n1;
                        resCur = n1;
                    }
                    else
                    {
                        resCur->next = n1;
                        resCur = n1;
                    }
                }
                sum = 0;
            }
            else
            {
                sum += node->val;
            }
            node = node->next;
        }
        return resHead;
    }
};