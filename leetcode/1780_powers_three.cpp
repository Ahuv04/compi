//https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
//1780. Check if Number is a Sum of Powers of Three
//using hint, just convert to ternary represntation and check if 2 is part of it
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int r;
        while(n>0){
            r=n%3;
            n/=3;
            if(r==2) return false;
        }

        return true;
        
    }
};