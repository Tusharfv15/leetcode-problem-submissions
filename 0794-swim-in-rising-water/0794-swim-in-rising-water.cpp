class Solution {
    typedef pair<int, pair<int, int>> pp;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        priority_queue<pp, vector<pp>, greater<>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (i == n - 1 && j == n - 1)
                ans = min(ans, currTime);

            int r[4] = {-1, 0, 1, 0};
            int c[4] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nr = i + r[k];
                int nc = j + c[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    if (currTime >= grid[nr][nc]) {
                        pq.push({currTime, {nr, nc}});
                    } else {
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return ans;
    }
};
