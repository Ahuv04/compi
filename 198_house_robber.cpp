//https://leetcode.com/problems/house-robber/
//198. House Robber
class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size()+1,-1);

        memo[0]=0;
        memo[1]=nums[0];
        for(int i=1;i<nums.size();i++)
        {   memo[i+1]=max(memo[i-1]+nums[i],memo[i]);

        }
        return memo[nums.size()];
    }
};