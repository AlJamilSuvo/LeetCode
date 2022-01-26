#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (true)
        {
            if (slow == nullptr || fast == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next;
            if (fast = nullptr)
                return nullptr;
                
        }
    }
};

int main()
{
    auto head = create_list_node({3, 2, 0, 4});
    print_list_node(head);
}