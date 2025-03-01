//https://leetcode.com/problems/house-robber-ii/
//213. House Robber II
class Solution {
public:

    int rob1(vector<int>& nums, int start, int end)
    {   int prev1, prev2, curr;
        prev1=0;
        prev2=nums[start];

        for(int i=start+1;i<end;i++)
        {   curr=max(prev1+nums[i],prev2);
            prev1=prev2;
            prev2=curr;
        }

        return max(prev1,prev2);

    }

    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }

        return max(rob1(nums,0,nums.size()-1),rob1(nums,1,nums.size()));

    }
};