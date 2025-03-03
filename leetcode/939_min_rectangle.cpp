//https://leetcode.com/problems/minimum-area-rectangle/
//939. Minimum Area Rectangle
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int,vector<int>> x;
        vector<int> x1;
        vector<int> y1;
        map<int,vector<int>> y;
        int ans=0;

        for(int i=0;i<points.size();i++){
            if(x.find(points[i][0])!=x.end()){
                x[points[i][0]].push_back(points[i][1]);
            }
            else{
                vector<int> t1;
                t1.push_back(points[i][1]);
                x[points[i][0]]=t1;
                x1.push_back(points[i][0]);
            }
            if(y.find(points[i][1])!=y.end()){
                y[points[i][1]].push_back(points[i][0]);
            }
            else{
                vector<int> t2;
                t2.push_back(points[i][0]);
                y[points[i][1]]=t2;
                y1.push_back(points[i][1]);
            }            
        }

        vector<int> t1;
        for(int i=0;i<x1.size();i++){
            t1=x[x1[i]];
            for(int j=0;j<t1.size();j++){
                for(int k=j+1;k<t1.size();k++){
                    for(int op=0;op<y[t1[j]].size();op++)
                    {   if(y[t1[j]][op] != x1[i] && find(y[t1[k]].begin(),y[t1[k]].end(),y[t1[j]][op])!=y[t1[k]].end())
                        {
                            if(ans==0)
                            {
                                ans=abs(x1[i]-y[t1[j]][op])*abs(t1[j]-t1[k]);
                            }
                            else{
                                ans=min(ans,abs(x1[i]-y[t1[j]][op])*abs(t1[j]-t1[k]));
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};