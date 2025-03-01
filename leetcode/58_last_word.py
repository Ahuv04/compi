#https://leetcode.com/problems/length-of-last-word/
#58. Length of Last Word
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        a=s.split()
        return len(a[-1])
        