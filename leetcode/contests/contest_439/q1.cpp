//Q1. Find the Largest Almost Missing Integer
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans=-1;
        if(k==1){
            sort(nums.begin(),nums.end());
            int prev=-1;
            bool ok=false;
            for(int i=nums.size()-1;i>=0;i--){
                if(prev==-1){
                    prev=nums[i];
                }
                else if(prev!=nums[i]){
                    if(ok){
                        ok=false;
                        prev=nums[i];
                    }
                    else{
                        return prev;
                    }
                }
                else{
                    ok=true;
                }
            }
            if(!ok) return nums[0];
            return -1;
        }
        else if(k==nums.size()){
            int temp=-1;
            for(int i=0;i<k;i++){
                temp=max(temp,nums[i]);        
            }
            return temp;
        }
        else if(k==0) return -1;
        else{
            int s=nums[nums.size()-1];
            bool ok1=false;
            bool ok2=false;
            for(int i=1;i<nums.size()-1;i++){
                if(nums[i]==nums[0]) ok1=true;
                if(s==nums[i]) ok2=true;
            }
            if(ok1 && ok2) return -1;
            if(nums[0]==nums[nums.size()-1]) return -1;
            if(ok1) return s;
            if(ok2) return nums[0];
            return max(nums[0],nums[nums.size()-1]);
        }
    }
};