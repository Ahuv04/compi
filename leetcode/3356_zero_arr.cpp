//https://leetcode.com/problems/zero-array-transformation-ii/
//3356. Zero Array Transformation II
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, queryCount = 0;
        vector<int> diffArray(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diffArray[i] < nums[i]) {
                queryCount++;
                if (queryCount > queries.size()) return -1;

                int left = queries[queryCount - 1][0], right = queries[queryCount - 1][1], value = queries[queryCount - 1][2];
                if (right >= i) {
                    diffArray[max(left, i)] += value;
                    if (right + 1 < diffArray.size()) {
                        diffArray[right + 1] -= value;
                    }
                }
            }
            sum += diffArray[i];
        }
        return queryCount;
    }
};

//time limit execeeded
// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n=nums.size();
//         int ans=0;
//         int p=n;

//         for(int i=0;i<n;i++){
//             if(nums[i]==0) p-=1;
//         }
//         if(p==0) return 0;

//         for(int i=0;i<queries.size();i++){
//             ans+=1;
//             for(int j=queries[i][0];j<=queries[i][1];j++){
//                 if(nums[j]>0){
//                     nums[j]=max(0,nums[j]-queries[i][2]);
//                     if(nums[j]==0) p-=1;
//                 }
//             }
//             if(p==0) return ans;
//         }
//         return -1;
//     }
// };