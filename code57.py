'''
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
'''

class Solution(object):
    def insert(self, intervals, newInterval):
        intervals.append(newInterval)
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
print(s.insert([[1,3],[6,9]],[2,5]))