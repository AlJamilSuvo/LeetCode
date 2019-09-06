
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        st=str(self.val)+'->'
        if self.next !=None:
            st+=str(self.next)
        return st

def reverseLL(hd):
    prev=None
    cur=hd
    nxt=None
    while cur !=None:
        nex=cur.next
        cur.next=prev
        prev=cur
        cur=nex
    return prev

def reverseCnt(p,hd,cnt):
        prev=None
        cur=hd
        nxt=None
        i=0
        while cur !=None and i<cnt:
            i+=1
            nex=cur.next
            cur.next=prev
            prev=cur
            cur=nex
        if p!=None:
            p.nex=cur
        hd.next=cur
        return prev,hd

def makeList(nums):
    head=ListNode(nums[0])
    cur=head
    for i in range(1,len(nums)):
        cur.next=ListNode(nums[i])
        cur=cur.next
    return head
hd=makeList([1,2,3,4,5,6])
print(hd)
fst,lst=reverseCnt(None,hd,3)
print(fst)
print(lst)