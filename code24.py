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
    def swapPairs(self, head):
        nxt=None
        prv=None
        cur=head
        while True:
            if cur==None or cur.next==None:
                if prv==None:
                    return head
                else:
                    prv.next=cur
                    return head
            else:
                fst=cur
                snd=cur.next
                nxt=snd.next
                snd.next=fst
                fst.next=nxt
                if prv==None:
                    head=snd
                else:
                    prv.next=snd
                cur=nxt
                prv=fst

def makeList(nums):
    head=ListNode(nums[0])
    cur=head
    for i in range(1,len(nums)-1):
        cur.next=ListNode(nums[i])
        cur=cur.next
    return head


hd=makeList([1,2,3,4,5,6,7,7,8])
print(hd)
s=Solution()
print(s.swapPairs(hd))