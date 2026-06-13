class Solution {
public:
    bool isSafe(vector<vector<char>>& board,char num, int row,int col){
        for(int i=0;i<9;i++){
            if(i != col && board[row][i]==num)
            return false;
            if(i != row && board[i][col]==num)
            return false;
            int r = 3*(row/3)+i/3;
            int c = 3*(col/3)+i%3;
            if((r != row || c != col) && board[r][c]==num)
            return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isSafe(board, board[i][j], i, j)) return false;
                }
            }
        }
        return true;
    }
};
