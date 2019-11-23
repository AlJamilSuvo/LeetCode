'''

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

'''

class Solution(object):
  
    def isMatch(self, s, p):
       
        self.dp=dict()
        return self.findMatch(s,p)
   
    def findMatch(self,s,p):
        print(s,p)
        if (s,p) in self.dp.keys():
            return self.dp[(s,p)]

        if len(p)==0 and len(s)==0:
            return True
        if len(p)==0 and len(s)!=0:
            return False
        currently_have_star=(len(p)>=2 and p[1]=='*')
        empty_string=len(s)==0

        print(currently_have_star,empty_string)

        if not currently_have_star and empty_string:
            return False
        
        first_match_result=True
        empty_star_result=currently_have_star
        one_forward_result=True
        star_forward_result=True
        if currently_have_star:
            empty_star_result=self.findMatch(s,p[2:])
        if not empty_string:
            first_char_match=s[0]==p[0]
            first_dot_match=p[0]=='.'
            first_match_result=first_char_match or first_dot_match
            if currently_have_star :
                star_forward_result=first_match_result and (self.findMatch(s[1:],p[2:]) or self.findMatch(s[1:],p)) 
            if not currently_have_star :
                one_forward_result= first_match_result and self.findMatch(s[1:],p[1:])
        result=empty_star_result or ((one_forward_result or star_forward_result) and first_match_result)
        self.dp[(s,p)]=result
        return result

sol=Solution()
while True:
    s=input()
    p=input()
    print(sol.isMatch(s,p))


'''
"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
'''