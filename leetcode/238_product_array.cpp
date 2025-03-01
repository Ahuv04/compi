//https://leetcode.com/problems/product-of-array-except-self/
//238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int a=1;
        int pos;
        int state=0;
        for(int i=0;i<nums.size();i++)
        {   if(state==0)
            {   if(nums[i]==0)
                {   state=1;
                    pos=i;
                }
                else{
                    a=a*nums[i];
                }
            }
            else if(state==1)
            {   if(nums[i]==0)
                {
                    state=2;
                    a=0;
                    break;
                }
                a=a*nums[i];
            }
        }

        if(state==2)
        {
            vector<int> ans(nums.size(),0);
            return ans;
        }
        if(state==1)
        {
            vector<int> ans(nums.size(),0);
            ans[pos]=a;
            return ans;
        }
        vector<int> ans(nums.size(),a);
        for(int i=0;i<nums.size();i++)
        {   
            ans[i]=ans[i]/nums[i];
                    
        }

        return ans;
    }
};