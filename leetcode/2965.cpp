//https://leetcode.com/problems/find-missing-and-repeated-values/
//2965. Find Missing and Repeated Values
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m=grid.size();
        map<int,int> m1;
        int no,dup;

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(m1.find(grid[i][j])==m1.end())   m1[grid[i][j]]=1;
                else dup=grid[i][j];
            }
        }

        for(int i=1;i<=m*m;i++){
            if(m1.find(i)==m1.end()){
                no=i;
                break;
            }
        }

        return {dup, no};
    }
};