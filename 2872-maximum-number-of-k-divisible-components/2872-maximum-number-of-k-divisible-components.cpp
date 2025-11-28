class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, int n, vector<int>& vis,int &cnt,vector<int>&values,int k) {
        vis[node] = 1;
        int sum = 0;
        sum = values[node];

        for (auto it : adj[node]) {
            if (!vis[it]) {
                sum+=dfs(it, adj, n, vis,cnt,values,k);
            }
        }

        if (sum % k == 0) {
            cnt++;
        }
        return sum % k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adjList(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n, 0);

        int ans = 0;
        dfs(0, adjList, n, vis,ans, values,k);
        return ans;
    }
};