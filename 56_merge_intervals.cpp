//https://leetcode.com/problems/merge-intervals/
//56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
                });
        
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