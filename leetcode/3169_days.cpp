//https://leetcode.com/problems/count-days-without-meetings/
//3169. Count Days Without Meetings
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int k=0;
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]>=meetings[k][0] && meetings[i][0]<=meetings[k][1]){
                meetings[k][1]=max(meetings[i][1],meetings[k][1]);
            }
            else{
                days=days-(meetings[k][1]-meetings[k][0]+1);
                k+=1;
                meetings[k][0]=meetings[i][0];
                meetings[k][1]=meetings[i][1];
            }
        }
        days=days-(meetings[k][1]-meetings[k][0]+1);
        return days;
    }
};