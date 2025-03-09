//https://leetcode.com/contest/weekly-contest-440/problems/choose-k-elements-with-maximum-sum/description/
//Q2. Choose K Elements With Maximum Sum

//working solution
//https://leetcode.com/problems/choose-k-elements-with-maximum-sum/
//3478. Choose K Elements With Maximum Sum
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long> ans(n,0);
        
        vector<pair<int,int>> idx;

        for(int i=0;i<n;i++){
            idx.push_back({nums1[i],i});
        }
        sort(idx.begin(),idx.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, long long> mp;

        long long sum=0;
        int j=0;

        for(int i=0;i<n;i++){
            int index=idx[i].second;

            while(j<i){
                int prev=idx[j].second;

                if(nums1[prev]>= nums1[index]) break;

                pq.push(nums2[prev]);
                sum+=nums2[prev];

                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                j++;
            }
            mp[index]=sum;
        }

        for(int i=0;i<n;i++){
            ans[i]=mp[i];
        }
        return ans;        
    }
};



//time limit execeeded
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> ans;
        int n=nums1.size();
        
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                if(nums1[j]<nums1[i]) v.push_back(nums2[j]);
            }
            sort(v.begin(),v.end(), greater<int>());
            long long s=0;
            int g=k;
            int j=0;
            while(g>0 && j<v.size()){
                if(v[j]>0) s+=v[j];
                else break;
                g--;
                j++;
            }
            ans.push_back(s);
        }
        return ans;        
    }
};©leetcode