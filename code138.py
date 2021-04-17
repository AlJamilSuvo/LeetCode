'''
A linked list of length n is given such that each node contains an additional
random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n
brand new nodes, where each new node has its value set to the value of its
corresponding original node. Both the next and random pointer of the new nodes
should point to new nodes in the copied list such that the pointers in the
original list and copied list represent the same list state. None of the
pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list,
where X.random --> Y, then for the corresponding two nodes x and y in the
copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each
node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random
pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

https://leetcode.com/problems/copy-list-with-random-pointer/


'''


class Node:  # Definition for a Node.
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random


def printList(head):
    s = ''
    while head is not None:
        s = s+str(head.val)
        if head.random is not None:
            s += '('+str(head.random.val)+')'
        else:
            s += '(null)'
        s += '->'
        head = head.next
    print(s)


class Solution(object):
    def copyRandomList(self, head):
        source_destination_map = {}
        new_head = None
        prev = None
        old_list_pointer = head
        while old_list_pointer is not None:
            n = Node(old_list_pointer.val)
            source_destination_map[old_list_pointer] = n
            if prev is not None:
                prev.next = n
            else:
                new_head = n
            prev = n
            old_list_pointer = old_list_pointer.next

        new_list_pointer = new_head
        old_list_pointer = head
        while new_list_pointer is not None:
            if old_list_pointer.random is not None:
                new_list_pointer.random = source_destination_map[old_list_pointer.random]
            new_list_pointer = new_list_pointer.next
            old_list_pointer = old_list_pointer.next

        return new_head


nums = [7, 13, 11, 10, 1]
random_index = [None, 0, 4, 2, 0]

nodeList = []
prev = None
for num in nums:
    n = Node(num)
    if prev is not None:
        prev.next = n
    nodeList.append(n)
    prev = n

for i in range(0, len(random_index)):
    index = random_index[i]
    if index is not None:
        nodeList[i].random = nodeList[index]

printList(nodeList[0])
s = Solution()
new_head = s.copyRandomList(nodeList[0])
printList(new_head)
