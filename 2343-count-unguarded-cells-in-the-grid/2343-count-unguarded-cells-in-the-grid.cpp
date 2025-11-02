class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, int dr, int dc) {
        int n = grid.size();
        int m = grid[0].size();
        while(r >=0 && r < n && c >=0 && c < m){
            if(grid[r][c] == 'G' || grid[r][c] == 'W')break;
            grid[r][c] = 'V';
            r+=dr;
            c+=dc;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '*'));
        
        for (auto& it : guards)
            grid[it[0]][it[1]] = 'G';
        for (auto& it : walls)
            grid[it[0]][it[1]] = 'W';
        
        for (auto& it : guards) {
            int r = it[0], c = it[1];
            dfs(r, c - 1, grid, 0, -1); // left
            dfs(r - 1, c, grid, -1, 0); // up
            dfs(r, c + 1, grid, 0, 1);  // right
            dfs(r + 1, c, grid, 1, 0);  // down
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '*') cnt++;

        return cnt;
    }
};
