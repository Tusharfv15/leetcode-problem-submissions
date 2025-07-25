class Solution {
public:
    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c) {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});
        return maxXor - minXor;
    }

    int dfs(int node, int par, int &time, vector<int>& nums, vector<vector<int>>& adj,
            vector<int>& storeXor, vector<int>& inTime, vector<int>& outTime) {

        storeXor[node] = nums[node];
        inTime[node] = time;
        time++;

        for (auto it : adj[node]) {
            if (it == par) continue;
            storeXor[node] ^= dfs(it, node, time, nums, adj, storeXor, inTime, outTime);
        }

        outTime[node] = time;
        time++;
        return storeXor[node];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        int result = INT_MAX;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> storeXor(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int time = 0;
        dfs(0, -1, time, nums, adj, storeXor, inTime, outTime);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xor1, xor2, xor3;
                if (isAncestor(i, j, inTime, outTime)) {
                    xor1 = storeXor[i] ^ storeXor[j];
                    xor2 = storeXor[j];
                    xor3 = storeXor[0] ^ xor1 ^ xor2;
                }
                else if (isAncestor(j, i, inTime, outTime)) {
                    xor1 = storeXor[i];
                    xor2 = storeXor[i] ^ storeXor[j];
                    xor3 = storeXor[0] ^ xor1 ^ xor2;
                }
                else {
                    xor1 = storeXor[i];
                    xor2 = storeXor[j];
                    xor3 = storeXor[0] ^ xor1 ^ xor2;
                }
                result = min(result, getScore(xor1, xor2, xor3));
            }
        }
        return result;
    }
};
