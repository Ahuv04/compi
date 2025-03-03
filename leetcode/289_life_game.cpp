//https://leetcode.com/problems/game-of-life/
//289. Game of Life
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n= m? board[0].size() : 0;

        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                count=0;
                for(int I=max(i-1,0);I<min(i+2,m);I++)
                {   for(int J=max(j-1,0);J<min(j+2,n);J++){
                        //AND board value with 1
                        count+=board[I][J] & 1;
                    }
                }
                //if conditions satisfy OR current value with 10
                if(count==3 || count-board[i][j]==3){
                    board[i][j] |=2;
                }
            }
        }

        //shift to the new latest bit
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j)
            {   board[i][j] >>= 1;}        
        }

        return;
    }
};