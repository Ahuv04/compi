//https://leetcode.com/problems/climbing-stairs/
//70. Climbing Stairs
class Solution {
public:
    map<int, int> m;
    int climbStairs(int n) {
        if(m.find(n)!=m.end())
        {   return m[n];}
        if(n==1) return 1;
        if(n==2) return 2;

        int ans=climbStairs(n-1)+climbStairs(n-2);
        m[n]=ans;
        return ans;
        
    }
};