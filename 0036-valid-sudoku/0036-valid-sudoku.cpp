class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

    

    vector<vector<int>>region(n,vector<int>(n,0));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if( i >=0 && i <=2 && j >=0 && j <=2){
                region[i][j] = 0;
            }
            if( i >=0 && i <=2 && j >=3 && j <=5){
                region[i][j] = 1;
            }
            if( i >=0 && i <=2 && j >=6 && j <=8){
                region[i][j] = 2;
            }
            if( i >=3 && i <=5 && j >=0 && j <=2){
                region[i][j] = 3;
            }
            if( i >=3 && i <=5 && j >=3 && j <=5){
                region[i][j] = 4;
            }
            if( i >=3 && i <=5 && j >=6 && j <=8){
                region[i][j] = 5;
            }
            if( i >=6 && i <=8 && j >=0 && j <=2){
                region[i][j] = 6;
            }
            if( i >=6 && i <=8 && j >=3 && j <=5){
                region[i][j] = 7;
            }
            if( i >=6 && i <=8 && j >=6 && j <=8){
                region[i][j] = 8;
            }
        }

    }
    vector<vector<int>>visRow(n,vector<int>(n,0));
    vector<vector<int>>visCol(n,vector<int>(n,0));
    vector<vector<int>>markReg(n,vector<int>(n,0));

    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int reg = region[i][j];
            if(board[i][j] == '.')continue;
            int num = (board[i][j] - '0')-1;
            if(markReg[reg][num])return false;

            if(visRow[i][num])return false;
            if(visCol[j][num])return false;

            markReg[reg][num] = 1;
            visRow[i][num] = 1;
            visCol[j][num] = 1;
        }
    }
    return true;

    }
};