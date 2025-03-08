//https://leetcode.com/problems/subarray-sum-equals-k/
//560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        if(nums[0]==k) ans+=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==k) ans+=1;
            nums[i]+=nums[i-1];
            if(nums[i]==k) ans+=1;
        }
        
        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[i-1]==k) ans+=1;
            }
        }

        return ans;
    }
};