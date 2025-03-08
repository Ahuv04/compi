//https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
//2379. Minimum Recolors to Get K Consecutive Black Blocks
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int ans=INT_MAX;
        int curr_st=0;
        int n=blocks.size();

        for(int i=0;i<k;i++){
            if(blocks[i]=='W') curr_st+=1;
        }
        ans=min(curr_st,ans);
        for(int i=1;i<=n-k;i++){
            if(blocks[i+k-1]!=blocks[i-1]){
                if(blocks[i-1]=='W') curr_st-=1;
                else curr_st+=1;
            }
            ans=min(ans,curr_st);
        }

        return ans;
    }
};