#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = head;
        ListNode *node = head->next;
        head->next = nullptr;
        while (node != nullptr)
        {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};