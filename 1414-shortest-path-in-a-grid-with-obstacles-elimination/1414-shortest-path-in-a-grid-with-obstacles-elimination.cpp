class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));

        pq.push({0, 0, 0, k});
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};
        dis[0][0][k] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int curr = it[0];
            int row = it[1];
            int col = it[2];
            int obs = it[3];
            pq.pop();

            for(int i = 0;i<4;i++){
                int nr = r[i] + row;
                int nc = c[i] + col;

                if(nr >=0 && nr < n && nc >=0 && nc < m){
                    if(grid[nr][nc] == 0){
                        if(curr + 1 < dis[nr][nc][obs]){
                            dis[nr][nc][obs] = curr + 1;
                            pq.push({curr+1,nr,nc,obs});
                        }
                    }
                    else {
                        if(obs > 0){
                            if(curr + 1 < dis[nr][nc][obs-1]){
                                dis[nr][nc][obs-1] = curr + 1;
                                pq.push({curr+1,nr,nc,obs - 1});
                            }
                        }
                    }
                }
            }

            
        }
      int ans = INT_MAX;

      for(int i = 0;i<=k;i++){
        ans = min(ans,dis[n-1][m-1][i]);
      }
      if(ans == INT_MAX) return -1;
      return ans;
    }
};