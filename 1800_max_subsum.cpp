//https://leetcode.com/problems/maximum-ascending-subarray-sum/
//1800. Maximum Ascending Subarray Sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int temp=nums[0];
        int ans=0;

        for(int i=1;i<nums.size();i++)
        {   if(nums[i-1]<nums[i])
            {
                temp+=nums[i];
            }
            else{
                ans=max(temp,ans);
                temp=nums[i];
            }
        }

        return max(temp, ans);
        
    }
};