#include "list_node_util.hpp"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr)
        {
            cout << slow->val << " " << fast->val << endl;
            fast = fast->next;
            if (fast == slow)
                return true;
            if (fast != nullptr)
                fast = fast->next;
            if (fast == slow)
                return true;
            slow = slow->next;
        }
        return false;
    }
};

int main()
{
    Solution s;
    ListNode *noCycle = create_list_node({1, 2, 3, 4, 5});
    cout << s.hasCycle(noCycle) << endl;

    ListNode *hasCycle = create_list_node_cycle({1, 2, 3, 4, 5}, 2);

    cout << s.hasCycle(hasCycle) << endl;
}