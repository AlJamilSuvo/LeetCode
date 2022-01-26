#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (true)
        {
            if (fast->next == nullptr)
                return slow;
            if (fast->next->next == nullptr)
                return slow->next;
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};