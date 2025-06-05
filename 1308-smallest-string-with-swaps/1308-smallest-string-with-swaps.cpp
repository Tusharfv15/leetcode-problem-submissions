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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet ds(n);
        for (auto it : pairs) {
            ds.Union(it[0], it[1]);
        }
        map<int, vector<int>> mpp;
        map<int, string> storeString;
        for (int i = 0; i < n; i++) {
            int root = ds.findUParent(i);
            mpp[root].push_back(i);
            storeString[root] += s[i];
        }

        /*    for (auto it : storeString) {
            sort(it.second.begin(), it.second.end());
        }
        for (auto it : mpp) {
            sort(it.second.begin(), it.second.end());
        } */

        for (auto it : mpp) {
            string& chars = storeString[it.first];
            sort(chars.begin(), chars.end());
            sort(it.second.begin(), it.second.end());
            for (int i = 0; i <it.second.size(); ++i) {
                s[it.second[i]] = chars[i];
            }
        }

        return s;
    }
};