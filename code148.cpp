#include "list_node_util.hpp"
using namespace std;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *prev = nullptr;
        ListNode *fast = head;
        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast == nullptr)
                break;
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        ListNode *curr = nullptr;
        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                if (curr == nullptr)
                {
                    head = left;
                }
                else
                    curr->next = left;
                curr = left;
                left = left->next;
            }
            else
            {
                if (curr == nullptr)
                {
                    head = right;
                }
                else
                    curr->next = right;
                curr = right;
                right = right->next;
            }

            if (left == nullptr)
                curr->next = right;
            if (right == nullptr)
                curr->next = left;
        }
        return head;
    }
};