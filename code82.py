'''


Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

'''
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        st=str(self.val)+'->'
        st+=str(self.next) if self.next!=None else 'None'
        return st

def to_link_list(lst):
    head=ListNode(lst[0])
    cur=head
    for l in lst[1:]:
        nw=ListNode(l)
        cur.next=nw
        cur=nw
    return head
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res=None
        pointer=None
        cur=head
        prev=None
        reject=True
        while cur!=None:
            if prev!=None and cur.val!=prev.val:
                if reject:
                    prev=None
                
                    pointer.next=prev
                pointer=prev
                if res==None:
                    res=pointer
                prev=None
            elif prev==None:
                prev=cur
            elif prev!=None and cur.val==prev.val:
                reject=True
            cur=cur.next
        return res
            
    
lst=[1,1,2,4,5,7,7]
hd=to_link_list(lst)
s=Solution()
res=s.deleteDuplicates(hd)
print(res)