#include <bits/stdc++.h>
#include "list_node_util.hpp"
using namespace std;

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *next = head->next;
        ListNode *prev = head;
        // print_list_node(head);
        while (next != nullptr)
        {

            // cout << "current->" << next->val << " " << prev->val << endl;

            current = next;
            // cout << "c=" << current->val << endl;
            next = current->next;
            if (prev != nullptr)
                prev->next = next;
            // cout << "rm c=";
            // print_list_node(head);

            if (current->val < head->val)
            {
                current->next = head;
                ListNode *temp = head;
                head = current;
                // cout << "new head=";
                // print_list_node(head);

                while (temp != nullptr && temp->next != next)
                {
                    // cout << "serarching prev af " << temp->val << endl;
                    temp = temp->next;
                }
                // cout << "prev->" << temp->val << endl;
                prev = temp;
            }
            else
            {
                ListNode *temp = head;
                // cout << temp->val << endl;
                while (temp->next != nullptr && temp->next != next)
                {
                    // cout << "post for " << current->val << " af " << temp->val << endl;
                    if (temp->next->val > current->val)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
                // cout << "new list->";
                // print_list_node(head);
                while (temp != nullptr && temp->next != next)
                {
                    // cout << "serarching prev af " << temp->val << endl;
                    temp = temp->next;
                }
                // cout << "prev->" << temp->val << endl;
                prev = temp;
            }
        }

        return head;
    }
};

int main()
{
    ListNode *head = create_list_node({-1, 5, 3, 4, 0});
    Solution s;
    ListNode *newHead = s.insertionSortList(head);
    print_list_node(newHead);
}