'''

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character

Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


'''


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        dp=dict()
        return self.findMinDistance(word1,word2,dp)
        
    def findMinDistance(self,word1,word2,dp):
        if len(word2)==0 or len(word1)==0:
            dis=len(word1)-len(word2)
            if dis<0:
                dis=-dis
            return dis
        key=(word1,word2)
        if word1==word2:
            return 0
        if key in dp.keys():
            return dp[key]
        if word1[0]==word2[0]:
            return self.findMinDistance(word1[1:],word2[1:],dp)
        else:
            insert_distance=self.findMinDistance(word1,word2[1:],dp)+1
            replace_distance=self.findMinDistance(word1[1:],word2[1:],dp)+1
            delete_distance=self.findMinDistance(word1[1:],word2,dp)+1
            min_distance=min(insert_distance,replace_distance)
            min_distance=min(min_distance,delete_distance)
            return min_distance


s=Solution()
print(s.minDistance('horse','ros'))
print(s.minDistance('intention','execution'))
print(s.minDistance('dinitrophenylhydrazine','acetylphenylhydrazine'))