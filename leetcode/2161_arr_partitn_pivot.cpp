//https://leetcode.com/problems/partition-array-according-to-given-pivot/
//2161. Partition Array According to Given Pivot
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int curr=0;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
                ans.push_back(nums[i]);
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }  
        return ans;      
    }
};
