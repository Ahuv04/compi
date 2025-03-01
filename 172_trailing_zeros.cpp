//https://leetcode.com/problems/factorial-trailing-zeroes/
//172. Factorial Trailing Zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        int a1=0;
        while(n>0)
        {   a1+=n/5;
            n/=5;
        }
        return a1;
        
    }
};