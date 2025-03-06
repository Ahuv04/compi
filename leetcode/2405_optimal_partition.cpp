//https://leetcode.com/problems/optimal-partition-of-string/
//2405. Optimal Partition of String
class Solution {
public:
    int partitionString(string s) {
        vector<char> v;
        int ans=1;

        for(int i=0;i<s.size();i++){
            if(find(v.begin(),v.end(),s[i])!=v.end()){
                ans+=1;
                v.clear();
            }
            v.push_back(s[i]);
        }

        return ans;

    }
};