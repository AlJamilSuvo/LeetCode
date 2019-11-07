class Solution(object):
    def merge(self, intervals):
        intervals.sort()
        ans=[]
        if len(intervals)<1:
            return []
        cur=intervals[0]
        for r in intervals:
            if r[0]>cur[1]:
                ans.append(cur)
                cur=r
            else:
                cur[1]=cur[1] if cur[1]>r[1] else r[1]
        ans.append(cur)
        return ans




s=Solution()
res=s.merge([[1,4],[-3,-0],[2,8],[1,3],[11,56]])
print(res)
res=s.merge([[1,4],[4,5]])
print(res)