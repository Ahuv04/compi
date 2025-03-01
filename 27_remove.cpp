//https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
//27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int p=-1;
        for (int i=0;i<nums.size();i++)
        {   if(nums[i]==val)
            {   if(p==-1)
                {   p=i;}
            }
            else{
                if(p!=-1)
                {   nums[p]=nums[i];
                    nums[i]=val;
                    p+=1;
                }
                k+=1;
            }
        }
        return k;
    }
};
