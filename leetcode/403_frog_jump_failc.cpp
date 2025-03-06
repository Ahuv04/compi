//https://leetcode.com/problems/frog-jump/
//403. Frog Jump
//unsolved as memory execeeded at 15th test case
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]>1) return false;

        int m=stones.size()-1;
        vector<int> v1,v2;
        int curr=0;
        v1.push_back(1);
        v2.push_back(1);

        while(curr!=v1.size()){
            if(v1[curr]==m){
                return true;
            }
            for(int i=v1[curr]+1;i<=m;i++){
                if(stones[i]-stones[v1[curr]]>=v2[curr]-1 && stones[i]-stones[v1[curr]]<=v2[curr]+1){
                    if(i==m) return true;
                    v1.push_back(i);
                    v2.push_back(stones[i]-stones[v1[curr]]);
                }
                else if(stones[i]-stones[v1[curr]]>v2[curr]+1) break;
            }
            curr+=1;
        }
        return false;
    }
};
