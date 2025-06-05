class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void Union(int u, int v) {
        int u_u = findUParent(u);
        int u_v = findUParent(v);
        if (u_u == u_v)
            return;
        if (size[u_u] < size[u_v]) {
            size[u_v] += size[u_u];
            parent[u_u] = u_v;
        } else {
            size[u_u] += size[u_v];
            parent[u_v] = u_u;
        }
    }
};


class Solution {

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n+1);
        if(edges.size() == 0) return(1LL*n*(n-1))/(1LL*2);
        for(auto it : edges){
            ds.Union(it[0],it[1]);
        }
       set<int>st;
        for(int i = 0;i<n;i++){
            int parent = ds.findUParent(i);
            st.insert(parent);
        }
        if(st.size() == 1) return 0;
        vector<int>storeSize;
        for(auto it : st){
            storeSize.push_back(ds.size[it]);
        }

       //if(storeSize.size() == 1) return 0;
        long long ans = 0;
       for(int i = 0;i<storeSize.size();i++){
        for(int j = i+1;j<storeSize.size();j++){
            ans += 1LL*storeSize[i]*1LL*storeSize[j];
        }
        
       }
       return ans;


    }
};