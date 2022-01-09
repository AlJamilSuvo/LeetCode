#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list_node(ListNode *list_node)
{
    ListNode *temp = list_node;
    while (temp != nullptr)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *create_list_node(vector<int> vct)
{
    ListNode *result = nullptr;
    ListNode *temp = nullptr;
    for (int i = 0; i < vct.size(); i++)
    {
        ListNode *new_list_node = new ListNode();
        new_list_node->val = vct[i];
        if (result == nullptr)
            result = new_list_node;

        if (temp != nullptr)
            temp->next = new_list_node;
        temp = new_list_node;
    }
    return result;
}