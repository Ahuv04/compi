//https://leetcode.com/problems/count-total-number-of-colored-cells/
//2579. Count Total Number of Colored Cells
class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        long long p=n*2-1;
        ans+=p;
        p-=2;

        while(p>0){
            ans+=2*p;
            p-=2;
        }

        return ans;
    }
};