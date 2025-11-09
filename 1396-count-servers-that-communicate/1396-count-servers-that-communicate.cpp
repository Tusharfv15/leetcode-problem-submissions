class Solution {
public:
    void dfs(int r, int c, int dr, int dc, vector<vector<int>>& grid, 
             vector<vector<int>>& vis, int n, int m) {
        int nr = r + dr;
        int nc = c + dc;
        while (nr >= 0 && nc >= 0 && nr < n && nc < m) {
            if (grid[nr][nc] == 1) {
                vis[nr][nc] = 1;
                vis[r][c] = 1;  // Mark the starting server as well
            }
            nr += dr;
            nc += dc;
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Mark all connected servers in each row/column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, -1, 0, grid, vis, n, m);  // Up
                    dfs(i, j, 1, 0, grid, vis, n, m);   // Down
                    dfs(i, j, 0, -1, grid, vis, n, m);  // Left
                    dfs(i, j, 0, 1, grid, vis, n, m);   // Right
                }
            }
        }
        
        // Count servers that are visited (connected to at least one other)
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};