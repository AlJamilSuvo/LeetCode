'''
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        st=str(self.val)+'->'
        if self.next==None:
            st+='None'
        else:
            st+=str(self.next)
        return st
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head==None:
            return head
        self.getLen(head)
        k=k%self.ln
        self.last.next=head
        prev=self.last
        cur=head
        k=self.ln-k
        for _ in range(k):
            prev=cur
            cur=cur.next
        prev.next=None
        head=cur
        return head
    def getLen(self,head):
        self.ln=0
        cur=head
        while cur!=None:
            if cur.next==None:
                self.last=cur
            cur=cur.next
            self.ln+=1

lst=[1,2]
head=ListNode(0)
cur=head

for l in lst:
    nLn=ListNode(l)
    cur.next=nLn
    cur=nLn
print(head)
s=Solution()
head=s.rotateRight(head,4)
print(head)