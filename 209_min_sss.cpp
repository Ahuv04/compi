//https://leetcode.com/problems/minimum-size-subarray-sum/
//209. Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int st=0, end=0;
        int ans=0;
        int temp=nums[st];

        while(st<nums.size() && end < nums.size()){
            if(temp>= target)
            {   if(ans==0) ans=end-st+1;
                ans=(ans==0)?end-st+1:min(ans,end-st+1);

                temp-=nums[st];
                st+=1;

                if(ans==1) return 1;
            }
            else {
                end+=1;
                if(end<nums.size()) temp+=nums[end];    
            }
        }

        return ans;
    }
};