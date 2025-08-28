class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, vector<int>> mpp;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({n-1,0});
        vis[n-1][0] = 1;

     
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            mpp[r-c].push_back(grid[r][c]);

            int rightRow = r;
            int rightCol = c+1;

            int topRow = r-1;
            int topCol = c;

            if(rightCol < m && !vis[rightRow][rightCol]){
                q.push({rightRow,rightCol});
                vis[rightRow][rightCol] = 1;
            }

            if(topRow >= 0 && !vis[topRow][topCol]){
                q.push({topRow,topCol});
                vis[topRow][topCol] = 1;
            }
        }

        
        for(auto &it : mpp){
            if(it.first >= 0){
                sort(it.second.begin(), it.second.end(), greater<int>()); // descending
            } else {
                sort(it.second.begin(), it.second.end()); // ascending
            }
        }

        
        unordered_map<int,int> idx; 
        vector<vector<int>> ans(n, vector<int>(m));

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                int key = r-c;
                ans[r][c] = mpp[key][idx[key]++];
            }
        }

        return ans;
    }
};
