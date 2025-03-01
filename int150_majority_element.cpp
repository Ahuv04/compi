//https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting, it says if one is in majority then it will stay in lead after whole iteration of voting
        int cand=nums[0];
        int count=1;

        for(int i=1;i<nums.size();i++)
        {
            if(cand!=nums[i])
            {
                count-=1;
                if(count<=0)
                {   cand=nums[i];
                    count=1;
                }
            }
            else{
                count+=1;
            }
        }
        return cand;    
    }
};