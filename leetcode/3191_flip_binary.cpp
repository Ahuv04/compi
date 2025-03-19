//https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
//3191. Minimum Operations to Make Binary Array Elements Equal to One I
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int k=0;
        int n=nums.size();

        while(k<n){
            if(nums[k]==0){
                ans+=1;
                if(k>n-3){
                    return -1;
                }
                nums[k]=1;
                nums[k+1]=1-nums[k+1];
                nums[k+2]=1-nums[k+2];
            }
            else{
                k++;
            }
        }
        return ans;
        
    }
};