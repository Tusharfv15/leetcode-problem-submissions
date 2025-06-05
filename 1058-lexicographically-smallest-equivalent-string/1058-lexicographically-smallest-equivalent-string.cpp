class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;  // ✅ Fix this
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DisjointSet ds(26);
        
        for(int i = 0; i < n; i++){
            ds.UnionBySize(s1[i] - 'a', s2[i] - 'a');
        }

        map<int, vector<int>> mpp;
        for(int i = 0; i < 26; i++){
            int root = ds.findUParent(i);  
            mpp[root].push_back(i);
        }

        for(auto &it : mpp){
            sort(it.second.begin(), it.second.end());
        }

        string ans;
        for(int i = 0; i < baseStr.size(); i++){
            int root = ds.parent[baseStr[i] - 'a'];
            ans += (char)(mpp[root][0] + 'a');
        }

        return ans;
    }
};
