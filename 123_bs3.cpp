//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
//123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int g1[n];
        int g2[n];
        int last=prices[0];
        int g=0;
        g1[0]=0;
        g2[0]=0;
        g2[n-1]=0;

        for(int i=1;i<n;i++)
        {   g1[i]=0;
            if(prices[i]>=last)
            {   
                g=max(g,prices[i]-last);
                g1[i]=g;
            }
            else
            { last=prices[i];
                g1[i]=g;
            }
        }
        last=prices[n-1];
        g=0;
        for(int i=n-2; i>=0;i--)
        {   g2[i]=0;
            if(prices[i]<=last)
            {
                g=max(g,last-prices[i]);
                // cout<<g<<endl;
                g2[i]=g;
            }
            else{
                last=prices[i];
                g2[i]=g;
            }
        }
        // cout<<"&&&"<<endl;
        g=0;
        for(int i=0;i<n;i++)
        {   g=max(g,g1[i]+g2[i]);
            //cout<<g1[i]<<endl;
            //cout<<g2[i]<<endl;
            //cout<<"-----"<<endl;
        }
        return g;
    }
};
