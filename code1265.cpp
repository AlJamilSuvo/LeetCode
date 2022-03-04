#include <bits/stdc++.h>
using namespace std;

class ImmutableListNode
{
public:
    void printValue();            // print the value of the node.
    ImmutableListNode *getNext(); // return the next node.
};

class Solution
{
public:
    void printLinkedListInReverse(ImmutableListNode *head)
    {
        stack<ImmutableListNode *> stk;
        while (head != nullptr)
        {
            stk.push(head);
            head = head->getNext();
        }
        while (!stk.empty())
        {
            stk.top()->printValue();
            stk.pop();
        }
        
    }
};