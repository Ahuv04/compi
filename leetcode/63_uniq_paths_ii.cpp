//https://leetcode.com/problems/unique-paths-ii/
//63. Unique Paths II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> arr(m,vector<int>(n));
        arr[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) arr[i][j]=0;
                else if(i>0 && j>0){
                    arr[i][j]=arr[i-1][j]+arr[i][j-1];
                }
                else{
                    if(i>0) arr[i][j]=arr[i-1][j];
                    else if(j>0) arr[i][j]=arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};