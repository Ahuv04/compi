//https://leetcode.com/problems/find-the-number-of-copy-arrays/
//3468. Find the Number of Copy Arrays
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bound) {
        int ans=bound[0][1]-bound[0][0]+1;
        for(int i=1;i<original.size();i++){
            bound[i][0]=max(bound[i-1][0]+original[i]-original[i-1],bound[i][0]);
            bound[i][1]=min(bound[i-1][1]+original[i]-original[i-1],bound[i][1]);
            if(bound[i][1]-bound[i][0]<0) return 0;
            ans=min(ans,max(0,bound[i][1]-bound[i][0]+1));
        }
        return ans;
    }
};