//152. Maximum Product Subarray
//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0;
        int p=1;
        int n=1;
        int k=-1;
        if(nums.size()==1)
        {   return nums[0];}

        for(int i=0;i<nums.size();i++)
        {   if(nums[i]==0)
            {   if(p>ans)
                {   ans=p;
                }
                p=1;
                n=1;
            }
            else if(nums[i]>0)
            {   p*=nums[i];
                n*=nums[i];
                k=0;
            }
            else{
                n*=nums[i];
                if(n>0)
                {   p=n;
                    k=0;
                }
                else{
                    if(p>ans)
                    {   ans=p;}
                    p=1;
                }
            }
        }
        if(p>ans)
        {   ans=p;
            k=0;
        }
        p=1;
        n=1;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {   if(p>ans)
                {   ans=p;
                    k=0;
                }
                p=1;
                n=1;

            }
            else if(nums[i]>0)
            {   p*=nums[i];
                n*=nums[i];
            }
            else{
                n*=nums[i];
                if(n>0)
                {   p=n;}
                else{
                    if(p>ans)
                    {   ans=p;}
                    p=1;
                }
            }

        }
        if(p>ans)
        {   ans=p;
        }

        if(k==-1)
        {return 0;}
        return ans;
    }
};
