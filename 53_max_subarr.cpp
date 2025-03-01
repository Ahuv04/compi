//https://leetcode.com/problems/maximum-subarray/
//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans=0;
        int temp=0;
        int neg_max=nums[0];
        bool c1=false;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
            {   ans=max(ans,temp);
                neg_max=max(neg_max,nums[i]);
                if(temp+nums[i]<0) temp=0;
                else temp+=nums[i];
            }
            else {
                c1=true;
                temp+=nums[i];
            }
        }
        if(c1) return max(ans,temp);

        return neg_max;
    }
};