class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
          int n = cost.size();
   
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    
   
    for (int ind = 0; ind <= n; ++ind) {
        dp[ind][0] = 0;
    }
    
    for (int ind = n - 1; ind >= 0; --ind) {
        for (int walls = 1; walls <= n; ++walls) {
         
            int paidPainter = cost[ind];
            int remaining_walls = walls - 1 - time[ind];
            if (remaining_walls < 0) remaining_walls = 0;
            paidPainter += dp[ind + 1][remaining_walls];
            
            
            int notTake = dp[ind + 1][walls];
            
            dp[ind][walls] = min(paidPainter, notTake);
        }
    }
    
    return dp[0][n];
    }
};