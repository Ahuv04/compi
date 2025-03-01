//https://leetcode.com/problems/combination-sum/
//39. Combination Sum
class Solution {
public:

    vector<vector<int>> cambi(vector<int>& v, int target, int st){
            vector<vector<int>> ans;
            vector<vector<int>> p;

            vector<int> temp;

            if(st==v.size()) return ans;
            if(v[st]>target) return ans;
            if(v[st]==target){
                temp.push_back(v[st]);
                ans.push_back(temp);
                return ans;
            }
            
            p=cambi(v,target-v[st],st);
            for(int k=0;k<p.size();k++){
                p[k].push_back(v[st]);
                ans.push_back(p[k]);
            }
            p=cambi(v,target-v[st],st+1);
            for(int k=0;k<p.size();k++){
                p[k].push_back(v[st]);
                ans.push_back(p[k]);
            }
            p=cambi(v,target,st+1);
            for(int k=0;k<p.size();k++){
                ans.push_back(p[k]);
            }   
            return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        vector<vector<int>> vec=cambi(v, target, 0);;
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end() );
        return vec;
    }
};