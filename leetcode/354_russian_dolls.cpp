//https://leetcode.com/problems/russian-doll-envelopes/
//354. Russian Doll Envelopes
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
        
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int i, j, n=envelopes.size();
        vector<int>lis;
        
        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{
                *it = envelopes[i][1];
            }
        }
        return lis.size();
    }
};

/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        int m=e.size();
        int ans=0;
        int temp=0;
        vector<vector<vector<int>>> bt;
        bool ok;

        for(int i=0;i<m;i++){
            ok=true;
            for(int j=0;j<temp;j++){
                if(e[i][0]>bt[j].back()[0] && e[i][1]>bt[j].back()[1]){
                    ok=false;
                    bt[j].push_back(e[i]);
                    int p=bt[j].size();
                    ans=max(ans,p);
                }
            }
            if(ok){
                temp+=1;
                bt.push_back({e[i]});
                ans=max(1,ans);
            }
        }

        return ans;        
    }
};
*/