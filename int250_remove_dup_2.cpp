//interview 150, https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count=1;
        int dup=nums[0];
        int ans=1;

        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i]==dup)
            {
                if(count<2)
                {   nums[ans]=nums[i];
                    ans+=1;
                    count+=1;
                }
            }
            else if(nums[i]>dup)
            {   count=1;
                nums[ans]=nums[i];
                ans+=1;
                dup=nums[i];
            }
        }
        return ans;
    }
};