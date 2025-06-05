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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n * m);
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int curr = i * m + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + r[k];
                        int nc = j + c[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            int neighbour = nr * m + nc;
                            if (grid[nr][nc] == 1 &&
                                ds.findUParent(neighbour) !=
                                    ds.findUParent(curr)) {
                                ds.Union(neighbour, curr);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    int curr = i * m + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + r[k];
                        int nc = j + c[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            if (grid[nr][nc] == 1) {
                                st.insert(ds.findUParent(nr * m + nc));
                            }
                        }
                    }
                    int temp = 1;
                    for (auto it : st) {
                        temp += ds.size[it];
                    }
                    ans = max(ans, temp);
                }
            }
        }

        if (ans == 0) {
            return n * m;
        }

        return ans;
    }
};
