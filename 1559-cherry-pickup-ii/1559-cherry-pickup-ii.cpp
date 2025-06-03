class Solution {
public:
int dp[70][70][70]; 


    int f(int i1, int j1, int j2, vector<vector<int>>& grid, int n, int m) {
        if (i1 >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return 0;

            if(dp[i1][j1][j2] !=-1) return dp[i1][j1][j2];

        int maxCherries = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int next_i1 = i1 + 1;
                int next_j1 = j1 + dj1;
                //int next_i2 = i2 + 1;
                int next_j2 = j2 + dj2;
                if(j1 == j2) maxCherries = max(maxCherries,  grid[i1][j1]+f(next_i1, next_j1, next_j2, grid, n, m));
                else maxCherries = max(maxCherries,  grid[i1][j1]+grid[i1][j2]+f(next_i1, next_j1, next_j2, grid, n, m));
            }
        }

       return dp[i1][j1][j2] = maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         memset(dp, -1, sizeof(dp)); 

        return f(0, 0, m - 1, grid, n, m);
    }
};
