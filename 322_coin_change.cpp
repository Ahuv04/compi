//https://leetcode.com/problems/coin-change/
//322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,-1);
        ans[0]=0;

        for(int i=0;i<=amount;i++)
        {   for(const int& k:coins)
            {   int s=i-k;
                if(s>=0 && ans[s]!=-1)
                {   if(ans[i]==-1) ans[i]=ans[s]+1;
                    else ans[i]=min(ans[s]+1,ans[i]);
                }
            }
        }
        
        return ans[amount];
    }
};