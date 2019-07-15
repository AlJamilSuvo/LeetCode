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
    def mergeTwoLists(self, l1, l2):
        dummyList=ListNode(-1000)
        cur=dummyList
        while l1!=None or l2!=None:
            if l1==None:
                cur.next=l2
                cur=l2
                l2=l2.next
            elif l2==None:
                cur.next=l1
                cur=l1
                l1=l1.next
            elif l1.val<=l2.val:
                cur.next=l1
                cur=l1
                l1=l1.next
            else:
                cur.next=l2
                cur=l2
                l2=l2.next
        return dummyList.next
a1=ListNode(1)
a2=ListNode(2)
a3=ListNode(4)
a1.next=a2
a2.next=a3

a4=ListNode(1)
a5=ListNode(3)
a6=ListNode(4)
a4.next=a5
a5.next=a6


s=Solution()
print(s.mergeTwoLists(a1,a4))




