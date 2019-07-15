# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        st=str(self.val)+'->'
        if self.next !=None:
            st+=str(self.next)
        return st

class Solution(object):
    def removeNthFromEnd(self, head, n):
        dummyHead=ListNode(0)
        dummyHead.next=head
        pnt=dummyHead
        for _ in range(n+1):
            pnt=pnt.next
        pnt_2=dummyHead
        while pnt!=None:
            pnt=pnt.next
            pnt_2=pnt_2.next
        pnt_2.next=pnt_2.next.next
        return dummyHead.next
    

head=ListNode(1)
cur=head
for  i in range(2,7):
    ll=ListNode(i)
    cur.next=ll
    cur=ll
print(head)
s=Solution()
print(s.removeNthFromEnd(head,6))
        