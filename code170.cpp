#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(int v) : val(v)
    {
    }
};

class TwoSum
{

    Node *head = nullptr;
    Node *tail = nullptr;

public:
    TwoSum()
    {
    }

    void add(int number)
    {
        if (head == nullptr)
        {
            head = new Node(number);
            tail = nullptr;
        }
        else if (tail == nullptr)
        {
            if (number < head->val)
            {
                tail = head;
                head = new Node(number);
                head->next = tail;
                tail->prev = 
            }
        }
    }

    bool find(int value)
    {
    }
};