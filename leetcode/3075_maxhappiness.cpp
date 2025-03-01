//3075. Maximize Happiness of Selected Children
//https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans=0;
        int n=happiness.size();
        for(int i=n-1;i>n-k-1;i--)
        {   if(happiness[i]>(n-1-i))
            {   ans+=happiness[i]-(n-1-i);

            }
        }
        
        return ans;
    }
};
