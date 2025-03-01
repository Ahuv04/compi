//https://leetcode.com/problems/gas-station/
//134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=-1;
        int state=0;
        int curr=0;
        int temp=0;
        for(int i=0;i<gas.size();i++)
        {   
            curr=curr+gas[i]-cost[i];

            if(state==0 && gas[i]-cost[i]>=0)
            {   cout<<i<<endl;
                ans=i;
                temp=gas[i]-cost[i];
                state=1;
            }
            else if(state==1)
            {   temp=temp+gas[i]-cost[i];
                if(temp<0)
                {
                    ans=-1;
                    state=0;
                }
            }
        }

        if(curr<0)
        {
            return -1;
        }
        return ans;
    }
};