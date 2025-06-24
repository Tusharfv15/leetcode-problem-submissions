class Solution {
public:
int res = 0;
    long long dfs(int node,int parent,vector<int>&cost,vector<vector<int>>&adj){

        vector<long long>paths;

        for(auto it : adj[node]){
            if(it == parent) continue;
            paths.push_back(dfs(it,node,cost,adj));
        }

        if(paths.size() == 0) return cost[node];

        long long maxSum = *max_element(paths.begin(),paths.end());
        for(auto it : paths){
            if(it < maxSum)res++;
        }
        return maxSum + 1LL*cost[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>>adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,cost,adj);
        return res;
    }
};