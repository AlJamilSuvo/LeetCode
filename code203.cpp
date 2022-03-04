#include <list_node_util.hpp>
using namespace std;

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        if (head == nullptr)
            return nullptr;
        ListNode *prev = head;
        ListNode *next = head->next;
        while (next != nullptr)
        {
            if (next->val == val)
            {
                prev->next = next->next;
            }
            else
                prev = next;

            next = next->next;
        }
        return head;
    }
};