#include "list_node_util.hpp"

class ListComparator
{
public:
    bool operator()(ListNode *x, ListNode *y)
    {
        return x->val > y->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        ListNode *head = nullptr;
        ListNode *resultNext = nullptr;
        priority_queue<ListNode *, vector<ListNode *>, ListComparator> que;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                que.push(lists[i]);
        }

        while (!que.empty())
        {
            ListNode *cur = que.top();
            que.pop();
            if (resultNext == nullptr)
            {
                resultNext = cur;
                head = cur;
            }
            else
                resultNext->next = cur;
            resultNext = cur;

            if (cur->next != nullptr)
                que.push(cur->next);
        }
        return head;
    }
};