//https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17
//2176. Count Equal and Divisible Pairs in an Array
class Solution {
public:
    int countPairs(vector<int>& nums, int p) {
        if(nums.size()==1) return 0;

        int ans=0;
        std::vector<int> indices(nums.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
            [&](int A, int B) -> bool {
                    return nums[A] < nums[B];
                });
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j] && (indices[i]*indices[j])%p==0) {
                    ans+=1;
                }
                else if(nums[i]!=nums[j]) break;
            }
        }

        return ans;
    }
};