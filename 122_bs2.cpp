//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int g=0;
        int last=prices[0];
        for(int i=1;i<prices.size();i++)
        {   if(prices[i]>=last)
            {   g+=prices[i]-last;
                last=prices[i];
            }
            else
            { last=prices[i];}
        }
        return g;               
    }
};
