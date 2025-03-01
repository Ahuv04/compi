//1st March
//https://leetcode.com/problems/apply-operations-to-an-array/
//2460. Apply Operations to an Array
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int temp=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0 && temp!=-1){
                nums[temp]=nums[i];
                nums[i]=0;
                temp+=1;
            }
            else if(nums[i]==0){
                if(temp==-1) temp=i;
            }
        }
        return nums;
    }
};