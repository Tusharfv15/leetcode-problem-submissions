class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[i][j] = 1;
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        
        long long totSum = grid[i][j];
        for (int k = 0; k < 4; k++) {
            int nr = i + r[k], nc = j + c[k];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] != 0) {
                totSum += dfs(nr, nc, vis, grid);
            }
        }
        return totSum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    long long totSum = dfs(i, j, vis, grid);
                    if (totSum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};
