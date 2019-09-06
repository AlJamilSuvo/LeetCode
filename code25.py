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
    def reverseKGroup(self, head, k):
        newHead=None
        hd=head
        p=None


        while hd!=None and hd.next!=None:
            fst,lst=self.reverseCnt(hd,k)
            if newHead==None:
                newHead=fst
            else:
                p.next=fst
            p=lst
            if lst==None:
                break
            hd=lst.next
        return newHead if newHead!=None else head
    def reverseCnt(self,hd,cnt):
        prev=None
        cur=hd
        nxt=None
        i=0
        while cur!=None and i<cnt:
            i+=1
            cur=cur.next
        if i<cnt:
            return hd,cur
        cur=hd
        i=0
        
        while cur !=None and i<cnt:
            i+=1
            nex=cur.next
            cur.next=prev
            prev=cur
            cur=nex
        hd.next=cur
        return prev,hd


def makeList(nums):
    head=ListNode(nums[0])
    cur=head
    for i in range(1,len(nums)):
        cur.next=ListNode(nums[i])
        cur=cur.next
    return head



hd=makeList([1,2,3,4,5,6,7,8,9,10,11,12])
s=Solution()
print(s.reverseKGroup(hd,5))