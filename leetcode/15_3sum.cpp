//https://leetcode.com/problems/3sum/
//15. 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){   
            return {};
        }
        sort(nums.begin(),nums.end());
        if(nums[0] > 0){       
            return {};
        }
        int pos,las;
        vector<vector<int>> v;
        int las_min,las_max;
        int i=0;
        while(i<nums.size()-2)
        {   pos=i+1;
            las=nums.size()-1;
            if(nums[i]+nums[pos]+nums[i+2]>0)
            {   break;
            }
            while(pos<las)
            {   if(nums[i]+nums[pos]+nums[las]==0)
                {   
                    v.push_back(vector<int>({nums[i],nums[pos],nums[las]}));
                    las_min=nums[pos];
                    las_max=nums[las];
                    while(pos<las && las_min==nums[pos])
                    {   pos++;
                    }
                    while(pos<las && las_max==nums[las])
                    {   las--;
                    }
                }
                else if(nums[i]+nums[pos]+nums[las]<0)
                {   pos+=1;
                }
                else{
                    las-=1;
                }
            }
            las_min=nums[i];
            i+=1;
            while(i<nums.size() && nums[i]==las_min)
            {   i+=1;

            }
        }
        return v;
    }
};