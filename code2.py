class Solution:
    def addTwoNumbers(self, l1,l2):
        a=0
        n=ListNode(0)
        res=None
        while l1!=None and l2!=None:
            n.next=ListNode((l1.val+l2.val+a)%10)
            a=(l1.val+l2.val+a)//10
            if(res==None):
                res=n.next
            n=n.next
            l1=l1.next
            l2=l2.next
        rm=l2 if l1==None else l1
        while rm!=None:
            n.next=ListNode((rm.val+a)%10)
            a=((rm.val+a)//10)
            n=n.next
            rm=rm.next
        if a==0:
            return res
        else:
            n.next=ListNode(a)
        return res