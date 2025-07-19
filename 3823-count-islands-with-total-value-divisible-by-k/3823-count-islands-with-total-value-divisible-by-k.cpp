class Solution {
public:
    long long f(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[i][j] = 1;
        int r[4] = {-1,0,1,0};
        int n = grid.size();
        int m = grid[0].size();
        int c[4] = {0,1,0,-1};
        long long totSum = grid[i][j];
        for(int k = 0;k<4;k++){
            int nr = i + r[k];
            int nc = j + c[k];

            if(nr >=0 && nc >=0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc]){
                    totSum += f(nr,nc,vis,grid);
            }
        
        }
        return totSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n+1,vector<int>(m+1,0));

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] !=0){
                    long long totSum = f(i,j,vis,grid);
                    if(totSum%k == 0)ans++;
                    
                }
            }
        }
        return ans;

    }
};