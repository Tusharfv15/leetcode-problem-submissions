class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];

        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            //if (row == n - 1 && col == m - 1) return dist;

            for (int i = 0; i < 4; i++) {
                int nr = row + r[i];
                int nc = col + c[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newDist = max(dist, grid[nr][nc]);
                    if (newDist < dis[nr][nc]) {
                        dis[nr][nc] = newDist;
                        pq.push({newDist, {nr, nc}});
                    }
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};
