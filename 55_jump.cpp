//https://leetcode.com/problems/jump-game/
//55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        bool ans=false;
        int curr=0;
        int n=nums.size()-1;
        for(int i=0;i<=curr;i++)
        {   if(curr>=n)
            {   return true;}
            curr=max(curr,i+nums[i]);
        }

        return false;
    }
};