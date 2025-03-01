//https://leetcode.com/problems/sqrtx/
//69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        int p;
        if(x==0) return 0;

        for(int i=1;i<=x/2;i++)
        {   p=x/i;
            if(p==i) return i;
            else if(p<i) return i-1;
        }
        return 1;
    }
};