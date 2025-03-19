//https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18
//2401. Longest Nice Subarray
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int temp=nums[0];
        int ans=1;
        int c=1;
        int n=nums.size();
        int prev=0;

        for(int i=1;i<n;i++){
            if(!(temp & nums[i])){
                c+=1;
                temp=temp | nums[i];
            }
            else{
                i=prev+1;
                prev=i;
                temp=nums[prev];
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
        
    }
};