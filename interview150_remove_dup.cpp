//https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup=-101;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>dup)
            {   nums[ans]=nums[i];
                ans+=1;
                dup=nums[i];
            }
        }
        return ans;
        
    }
};