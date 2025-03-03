//https://leetcode.com/problems/set-matrix-zeroes/description/
//73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n= m? matrix[0].size() : 0;
        vector<int> x;
        vector<int> y;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(find(x.begin(),x.end(),i)==x.end()) x.push_back(i);
                    if(find(y.begin(),y.end(),j)==y.end()) y.push_back(j);
                }
            }
        }
        for(int i=0;i<x.size();i++){
            for(int j=0;j<n;j++){
                matrix[x[i]][j]=0;
            }
        }
        for(int i=0;i<y.size();i++){
            for(int j=0;j<m;j++){
                matrix[j][y[i]]=0;
            }
        }
        return;
    }
};