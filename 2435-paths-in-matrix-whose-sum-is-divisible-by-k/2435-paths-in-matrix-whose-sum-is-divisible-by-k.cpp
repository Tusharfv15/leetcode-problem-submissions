class Solution {
public:
    const int mod = 1e9 + 7;
    int f(int i, int j, int n, int m, int k, int rem,
          vector<vector<int>>& grid,vector<vector<vector<int>>>&dp) {
        if (i == n - 1 && j == m - 1) {
            int mod;
            if (rem != -1)
                mod = (rem + grid[i][j]) % k;
            else
                mod = grid[i][j] % k;

            if (mod == 0)
                return 1;
            else
                return 0;
        }
        if(dp[i][j][rem+1] !=-2) return dp[i][j][rem+1];
        int newMod;
        if (rem != -1)
            newMod = (rem + grid[i][j]) % k;
        else
            newMod = grid[i][j] % k;
        int down = 0;
        int right = 0;
        if (i + 1 < n) {
            down = f(i + 1, j, n, m, k, newMod, grid,dp) % mod;
        }
        if (j + 1 < m)
            right = f(i, j + 1, n, m, k, newMod, grid,dp) % mod;

        return dp[i][j][rem+1] = (down + right) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -2)));
        return f(0, 0, n, m, k, -1, grid, dp);
    }
};