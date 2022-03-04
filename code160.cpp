#include "list_node_util.hpp"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        stack<ListNode *> stkA;
        stack<ListNode *> stkB;
        ListNode *temp = headA;
        while (temp != nullptr)
        {
            stkA.push(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr)
        {
            stkB.push(temp);
            temp = temp->next;
        }
        ListNode *result = nullptr;
        while (!stkA.empty() && !stkB.empty() && stkA.top() == stkB.top())
        {
            result = stkA.top();
            stkA.pop();
            stkB.pop();
        }
        return result;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        unordered_map<ListNode *, bool> seen;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != nullptr || tempB != nullptr)
        {
            if (tempA != nullptr)
            {
                if (seen[tempA])
                    return tempA;
                seen[tempA] = true;
                tempA = tempA->next;
            }

            if (tempB != nullptr)
            {
                if (seen[tempB])
                    return tempB;
                seen[tempB] = true;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA != ptrB)
        {
            ptrA = ptrA == nullptr ? headB : ptrA->next;
            ptrB = ptrB == nullptr ? headA : ptrB->next;
        }

        return ptrA;
    }
};