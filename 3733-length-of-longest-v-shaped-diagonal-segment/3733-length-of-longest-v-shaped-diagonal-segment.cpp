class Solution {
    vector<vector<int>> directions = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

public:
    int dfs(int i, int j, int d, vector<vector<int>>& grid, bool expectTwo, bool hasTurned) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Check bounds
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        
        // Check if current cell matches what we expect
        int expectedVal = expectTwo ? 2 : 0;
        if (grid[i][j] != expectedVal) {
            return 0;
        }
        
        int maxLen = 0;
        
        // Continue in same direction
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        maxLen = max(maxLen, 1 + dfs(ni, nj, d, grid, !expectTwo, hasTurned));
        
        // Try making a clockwise 90-degree turn (only if haven't turned yet)
        if (!hasTurned) {
            int newDir = (d + 1) % 4; // This is actually clockwise for our direction array
            int ti = i + directions[newDir][0];
            int tj = j + directions[newDir][1];
            maxLen = max(maxLen, 1 + dfs(ti, tj, newDir, grid, !expectTwo, true));
        }
        
        return maxLen;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxLength = 0;
        
        // Find all starting points (cells with value 1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Try starting in each diagonal direction
                    for (int d = 0; d < 4; d++) {
                        int ni = i + directions[d][0];
                        int nj = j + directions[d][1];
                        // After 1, we expect 2 (start with expectTwo = true)
                        int length = 1 + dfs(ni, nj, d, grid, true, false);
                        maxLength = max(maxLength, length);
                    }
                }
            }
        }
        
        return maxLength;
    }
};