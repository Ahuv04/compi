//https://leetcode.com/problems/optimal-partition-of-string/
//2405. Optimal Partition of String
class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        int flag=0;

        for(int i=0;i<s.size();i++){
            int val=s[i]-'a';
            if(flag & 1<<val){
                flag=0;
                ans+=1;

            }
            flag |= 1<<val;

        }

        return ans;

    }
};