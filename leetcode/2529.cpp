//https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
//2529. Maximum Count of Positive Integer and Negative Integer
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans+=1;
            }
            else if(nums[i]>0){
                ans=max(ans,n-i);
                return ans;
            }
        }
        return ans;
    }
};