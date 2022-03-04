#include "list_node_util.hpp"

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> stk;
        ListNode *node = head;
        while (node != nullptr)
        {
            stk.push(node);
            node = node->next;
        }
        node = head;
        while (stk.top() != node)
        {
            ListNode *next = node->next;
            ListNode *s = stk.top();
            stk.pop();
            if(next==s) break;
            node->next = s;
            
            s->next = next;
            stk.top()->next = nullptr;
            node = next;
        }
    }
};

int main()
{
    ListNode *head = create_list_node({1, 2, 3, 4});
    Solution s;
    s.reorderList(head);
}