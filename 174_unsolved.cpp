//https://leetcode.com/problems/dungeon-game/
//174. Dungeon Game
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>> v1(m,vector<int>(n));
        vector<vector<int>> v2(m,vector<int>(n));

        v1[0][0]=dungeon[0][0]<0?dungeon[0][0]:0;
        v2[0][0]=dungeon[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0 && i>0){
                    v2[i][j]=max(v2[i][j-1])
                }
                else if(i>0){
                    v2[i][j]=v2[i-1][j]+dungeon[i][j];
                    if(dungeon[i][j]<0){
                       if(v2[i-1][j]<=0){
                        v1[i][j]=v1[i-1][j]+dungeon[i][j];
                       }
                       else{
                        v1[i][j]=
                       }
                    }
                }
                else{

                }
            }
        }
        return -1*v1[m-1][n-1]+1;
    }
};