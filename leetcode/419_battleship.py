#https://leetcode.com/problems/battleships-in-a-board/
#419. Battleships in a Board
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        ans=0
        x_pos=0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='X':
                    if (i==0 and j==0) or (i==0 and j!=0 and board[i][j-1]!='X') or (j==0 and i!=0 and board[i-1][j]!='X') or  (i!=0 and board[i-1][j]!='X' and j!=0 and board[i][j-1]!='X'):
                        ans+=1        
        return ans