#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        stack<ListNode *> slowStack;
        stack<ListNode *> fastStack;
        slowStack.push(slow);
        fastStack.push(fast);
        while (true)
        {
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next;
            fastStack.push(fast);
            if (slow == fast)
                break;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next;
            fastStack.push(fast);
            if (slow == fast)
                break;
            slow = slow->next;
            slowStack.push(slow);
        }
        ListNode *lastSlow = nullptr;
        while (!slowStack.empty())
        {
            cout << slowStack.top()->val << " " << fastStack.top()->val << endl;
            if (slowStack.top() != fastStack.top())
                break;
            lastSlow = slowStack.top();
            slowStack.pop();
            fastStack.pop();
        }
        return lastSlow;
    }
};

int main()
{
    auto head = create_list_node({3, 2, 0, 4});
    Solution s;
    ListNode *r = s.detectCycle(head);
    cout << r << " ";
    if (r != nullptr)
        cout << r->val;
    cout << endl;
}