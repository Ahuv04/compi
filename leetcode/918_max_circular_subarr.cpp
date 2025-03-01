//https://leetcode.com/problems/maximum-sum-circular-subarray/
//918. Maximum Sum Circular Subarray
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=nums[0];
        int curr_ans=0;
        int total=0;
        int min_overall=nums[0];
        int curr_min=0;

        for(int i=0;i<nums.size();i++)
        {   
            curr_ans=max(curr_ans+nums[i],nums[i]);
            ans=max(ans,curr_ans);
            curr_min=min(curr_min+nums[i],nums[i]);
            min_overall=min(curr_min,min_overall);
            total+=nums[i];
        }

        return ans>0? max(ans,total-min_overall) : ans;
    }

};