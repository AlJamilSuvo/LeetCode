#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr)
            return slow->next;

        cout<<fast->val<<endl;
        while (fast != nullptr)
        {
            fast = fast->next;
            if(fast==nullptr) break;
            slow = slow->next;
            
        }
        cout<<slow->val<<endl;
        slow->next = slow->next->next;
        return head;
    }
};