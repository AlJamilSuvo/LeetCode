class Solution:
    def lengthOfLongestSubstring(self, s):
        res=''
        cur=''
        for ch in s:
            print(ch,cur)
            if ch in cur:
                res=cur if len(cur)>len(res) else res
                cur=cur[cur.index(ch)+1:]+ch
            else:
                 cur=cur+ch
        res=cur if len(cur)>len(res) else res
        return len(res)

s=Solution()
print(s.lengthOfLongestSubstring('abcabcbb'))
print(s.lengthOfLongestSubstring('bbbbb'))
print(s.lengthOfLongestSubstring('dvdf'))




        