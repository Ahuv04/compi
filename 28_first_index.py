#https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150
#28. Find the Index of the First Occurrence in a String

class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(haystack)<len(needle):
            return -1
        state=0
        temp=0
        ans=-1
        i=0
        while i<len(haystack) and (len(haystack)-i)>=len(needle):
            if needle[0]==haystack[i]:
                ans=i
                #print(ans)
                temp=0
                while needle[temp]==haystack[i]:
                    temp+=1
                    i+=1
                    if temp==len(needle):
                        return ans
                i=ans
            i+=1

        return -1

        