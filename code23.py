from queue import PriorityQueue
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
    def mergeKLists(self, lists):
        if len(lists)==0:
            return None
        if len(lists)==1:
            return lists[0]
        elif len(lists)==2:
            return self.mergeTwoLists(lists[0],lists[1])
        else:
            mid=int(len(lists)/2)
            res1=self.mergeKLists(lists[:mid])
            res2=self.mergeKLists(lists[mid:])
            return self.mergeTwoLists(res1,res2)
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

def makeList(nums):
    head=ListNode(nums[0])
    cur=head
    for i in range(1,len(nums)):
        cur.next=ListNode(nums[i])
        cur=cur.next
    return head

lists=[]
lists.append(makeList([1,4,5]))
lists.append(makeList([1,3,4]))
lists.append(makeList([2,6]))
s=Solution()
print(s.mergeKLists(lists))
