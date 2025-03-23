//https://leetcode.com/problems/spiral-matrix/
//54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();

        // if(m==1 && n==1){
        //     ans.push_back(matrix[0][0]);
        //     return ans;
        // }

        vector<vector<bool>> v(m, vector<bool>(n,0));
        int i=0;
        int j=0;
        int c=0;

        while(i<m && j<n && i>=0 && j>=0){
            if(v[i][j]) break;
            ans.push_back(matrix[i][j]);
            v[i][j]=true;
            if(c==0){
                if(j+1==n || v[i][j+1]){
                    c=1;
                    i+=1;
                }
                else j+=1;
            }
            else if(c==1){
                if(i+1==m || v[i+1][j]){
                    c=2;
                    j-=1;
                }
                else i+=1;
            }
            else if(c==2){
                if(j-1<0 || v[i][j-1]){
                    c=3;
                    i-=1;
                }
                else j-=1;
            }
            else if(c==3){
                if(i-1<0 || v[i-1][j]){
                    c=0;
                    j+=1;
                }
                else i-=1;
            }
        }

        return ans;
    }
};