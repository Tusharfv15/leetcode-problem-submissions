class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Run DFS from Pacific border
        for (int i = 0; i < n; i++) dfs(i, 0, pacific, heights);
        for (int j = 0; j < m; j++) dfs(0, j, pacific, heights);

        // Run DFS from Atlantic border
        for (int i = 0; i < n; i++) dfs(i, m - 1, atlantic, heights);
        for (int j = 0; j < m; j++) dfs(n - 1, j, atlantic, heights);

        // Collect cells reachable by both
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& h) {
        vis[i][j] = 1;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                !vis[ni][nj] && h[ni][nj] >= h[i][j]) {
                dfs(ni, nj, vis, h);
            }
        }
    }
};
