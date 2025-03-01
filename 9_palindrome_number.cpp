//https://leetcode.com/problems/palindrome-number/
//9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        double ans=0;
        int temp=x;

        while(temp>0)
        {   ans=ans*10+temp%10;
            temp/=10;
        }
        if(ans==x) return true;
        return false;
        
    }
};