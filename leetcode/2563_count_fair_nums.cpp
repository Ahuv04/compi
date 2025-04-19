//https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2025-04-19
//2563. Count the Number of Fair Pairs
class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long ans = 0;
            sort(nums.begin(), nums.end());
            for (int i = 0; i + 1 < nums.size(); i++) {
                int minReq = lower - nums[i], maxReq = upper - nums[i];
                auto high = upper_bound(nums.begin() + i + 1, nums.end(), maxReq);
                auto low = lower_bound(nums.begin() + i + 1, nums.end(), minReq);
                ans += (high - low);
            }
            return ans;
        }
    };

//time limit exceeded
// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int ans=0;
//         if(nums.size()==1) return ans;
//         sort(nums.begin(),nums.end());
//         int k=nums.size();

//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<k;j++){
//                 if((nums[i]+nums[j]<=upper)&&(nums[i]+nums[j]>=lower)){
//                     ans+=1;
//                     // cout<<nums[i]<<" "<<nums[j]<<endl;
//                 }
//                 else if(nums[i]+nums[j]>upper){
//                     k=j;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };