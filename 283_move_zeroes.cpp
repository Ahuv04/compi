//283. Move Zeroes
//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr=-1;

        for(int i=0;i<nums.size();i++)
        {   if(curr==-1 && nums[i]==0)
            {
                curr=i;
            }
            else if(nums[i]!=0 && curr!=-1)
            {
                nums[curr]=nums[i];
                nums[i]=0;
                curr+=1;
            }
        }
        return ;
    }
};