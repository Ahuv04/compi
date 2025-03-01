//https://leetcode.com/problems/longest-increasing-subsequence/
//300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int k=0;
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {   
            for(int j=i-1;j>=0;j--)
            {   if(nums[j]<nums[i])
                {   ans[i]=max(ans[i],ans[j]+1);}
            }
            k=max(ans[i],k);
        }

        return k;
        
    }
};