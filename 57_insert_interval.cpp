//https://leetcode.com/problems/insert-interval/
//57. Insert Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool state=true;


        for(int i=0;i<intervals.size();i++)
        {   if(intervals[i][0]<=newInterval[0]&&intervals[i][1]>=newInterval[1]) return intervals;
            else if(intervals[i][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i,newInterval);
                return intervals;
            }
            else if((newInterval[0]<=intervals[i][1] && newInterval[1]>intervals[i][1])
            || (newInterval[0]<intervals[i][0] && newInterval[1]>=intervals[i][0]))
            {   intervals[i][0]=min(intervals[i][0],newInterval[0]);
                intervals[i][1]=max(intervals[i][1],newInterval[1]);
                state=false;
                break;
            }
        }

        if(state){
            intervals.push_back(newInterval);
            return intervals;            
        }

        vector<vector<int>> ans;
        int st=0;
        int curr=1;

        for(int i=curr;i<intervals.size();i++)
        {
            if(intervals[i][0]<=intervals[st][1])
            {   intervals[st][1]=max(intervals[st][1],intervals[i][1]);}
            else{
                st+=1;
                intervals[st][0]=intervals[i][0];
                intervals[st][1]=intervals[i][1];
            }
        }

        for(int i=0;i<=st;i++)
        {
            ans.push_back(intervals[i]);
        }
        return ans;

    }
};