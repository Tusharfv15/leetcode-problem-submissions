class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        // storeVal[diag] = all elements on that diagonal
        unordered_map<int, vector<int>> storeVal;
        int maxDiag = 0;

        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();

            int diag = i + j;
            storeVal[diag].push_back(mat[i][j]);
            maxDiag = max(maxDiag, diag);

            // right
            if(j+1 < m && !vis[i][j+1]) {
                q.push({i, j+1});
                vis[i][j+1] = 1;
            }
            // down
            if(i+1 < n && !vis[i+1][j]) {
                q.push({i+1, j});
                vis[i+1][j] = 1;
            }
        }

        vector<int> res;
        for(int d = 0; d <= maxDiag; d++) {
            if(d % 2 == 0) {
                reverse(storeVal[d].begin(), storeVal[d].end());
            }
            for(int val : storeVal[d]) {
                res.push_back(val);
            }
        }

        return res;
    }
};
