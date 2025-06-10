class Solution {
public:
    bool dfs(int row, int col, vector<vector<char>>& board, string word, string res, vector<vector<int>>& vis) {
        if (res == word) return true;
        if (res.size() >= word.size()) return false;
        if (res.back() != word[res.size() - 1]) return false;
        
        int n = board.size();
        int m = board[0].size();
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r[i] + row;
            int nc = c[i] + col;

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                res += board[nr][nc];
                if (dfs(nr, nc, board, word, res, vis)) return true;
                res.pop_back();
                vis[nr][nc] = 0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    string res;
                    res += board[i][j];
                    vis[i][j] = 1;
                    if (dfs(i, j, board, word, res, vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};