#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node != nullptr)
        {
            ListNode *n1 = node->next;
            if (n1 == nullptr)
                break;

            ListNode *newNext = n1->next;

            if (prev == nullptr)
                head = n1;
            else
                prev->next = n1;
            n1->next = node;
            node->next = newNext;
            prev = node;
            node = newNext;
        }
        return head;
    }
};