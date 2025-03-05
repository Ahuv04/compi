//https://leetcode.com/problems/edit-distance/
//72. Edit Distance
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.length();
        int w2=word2.length();

        vector<vector<int>> v(w1+1, vector<int>(w2+1));

        v[0][0]=0;

        for(int i=1;i<=w1;i++) 
            v[i][0]=i;

        for(int j=1;j<=w2;j++)
            v[0][j]=j;

        for(int i=1;i<=w1;i++){
            for(int j=1;j<=w2;j++){
                if(word1[i-1]==word2[j-1])  v[i][j] =v[i-1][j-1];
                else{
                    v[i][j]=min({v[i-1][j-1],v[i-1][j],v[i][j-1]})+1;
                }
            }
        }

        return v[w1][w2];
    }
};