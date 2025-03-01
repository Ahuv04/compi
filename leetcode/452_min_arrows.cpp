//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//452. Minimum Number of Arrows to Burst Balloons
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {

        if(intervals.size()==1) return 1;

        sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
                });
        
        int st=0;
        int curr=1;

        for(int i=curr;i<intervals.size();i++)
        {
            if(intervals[i][0]<=intervals[st][1])
            {   
                intervals[st][0]=max(intervals[st][0],intervals[i][0]);
                intervals[st][1]=min(intervals[st][1],intervals[i][1]);
            }
            else{
                st+=1;
                intervals[st][0]=intervals[i][0];
                intervals[st][1]=intervals[i][1];
            }
        }

        return ++st;
    }
};