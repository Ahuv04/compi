#https://leetcode.com/problems/reverse-words-in-a-string/
#151. Reverse Words in a String
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        a=s.split()
        a.reverse()
        s=""
        state=0
        for i in range(len(a)):
            if state==0:
                s+=a[i]
                state=1
            else:
                s=s+" "+a[i]

        return s
        
        