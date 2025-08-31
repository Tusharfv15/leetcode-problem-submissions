class Solution {
public:
    bool isValid(int i,int j, char d,vector<vector<char>>&board){
        for(int k = 0;k<9;k++){
            if(board[k][j] == d) return false;
        }
        for(int k = 0;k<9;k++){
            if(board[i][k] == d) return false;
        }

        int start_i = (i/3)*3;
        int start_j = (j/3)*3;

        for(int l = 0;l<3;l++){
            for(int m = 0;m<3;m++){
                if(board[start_i+l][start_j+m] == d)return false;
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>&board){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){

                for(char d = '1'; d<='9';d++){
                    if(isValid(i,j,d,board)){
                        board[i][j] = d;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                 return false;
                }
               
               
            }
            
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();

        solve(board);
    }
};