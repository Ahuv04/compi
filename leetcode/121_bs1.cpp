//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int g=0;
        int last=prices[0];
        for(int i=1;i<prices.size();i++)
        {   if(prices[i]>=last)
            {   
                g=max(g,prices[i]-last);
            }
            else
            { last=prices[i];}
        }
        return g;        
    }
};
