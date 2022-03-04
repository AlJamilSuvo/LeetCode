#include <bits/stdc++.h>
using namespace std;

class LRUNode
{
public:
    int value;
    int key;
    LRUNode *next;
    LRUNode *prev;
};

class LRUCache
{
    int capasity = 0;
    int size = 0;
    LRUNode *head = nullptr;
    LRUNode *tail = nullptr;
    unordered_map<int, LRUNode *> keyMap;

    void putNodeToFront(LRUNode *node)
    {
        if (node == head)
            return;

        if (node == tail && node->next != nullptr)
            tail = node->next;
        if (node->next != nullptr)
            node->next->prev = node->prev;
        if (node->prev != nullptr)
            node->prev->next = node->next;
        head->next = node;
        node->prev = head;
        node->next = nullptr;
        head = node;
    }

public:
    LRUCache(int cap) : capasity(cap)
    {
    }

    int get(int key)
    {
        LRUNode *node = keyMap[key];
        if (node == nullptr)
            return -1;
        putNodeToFront(node);
        return node->value;
    }

    void put(int key, int value)
    {
        LRUNode *node = keyMap[key];
        if (node != nullptr)
        {
            node->value = value;
            putNodeToFront(node);
        }
        else
        {
            if (size == capasity)
            {
                keyMap[tail->key] = nullptr;
                tail->value = value;
                tail->key = key;
                keyMap[key] = tail;
                putNodeToFront(tail);
            }
            else
            {
                size += 1;
                node = new LRUNode();
                node->value = value;
                node->key = key;
                keyMap[key] = node;
                if (head == nullptr && tail == nullptr)
                {
                    head = node;
                    tail = node;
                }
                else
                {
                    head->next = node;
                    node->prev = head;
                    head = node;
                }
            }
        }
    }
};
