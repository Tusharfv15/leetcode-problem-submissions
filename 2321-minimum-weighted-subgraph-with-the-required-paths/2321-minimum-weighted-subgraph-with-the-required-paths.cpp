class Solution {
public:
    vector<long long> dijkstra(int src, vector<vector<pair<int, long long>>>& adj) {
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [wt, node] = pq.top(); pq.pop();
            if (wt > dist[node]) continue;

            for (auto [adjNode, adjWt] : adj[node]) {
                if (dist[adjNode] > wt + adjWt) {
                    dist[adjNode] = wt + adjWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    vector<vector<pair<int, long long>>> adj(n), revAdj(n);

    for (auto& e : edges) {
        int u = e[0], v = e[1];
        long long w = e[2];
        adj[u].emplace_back(v, w);
        revAdj[v].emplace_back(u, w); // reversed graph
    }

    vector<long long> d1 = dijkstra(src1, adj);     // src1 -> all
    vector<long long> d2 = dijkstra(src2, adj);     // src2 -> all
    vector<long long> d3 = dijkstra(dest, revAdj);  // all -> dest (via reversed graph)

    long long ans = LLONG_MAX;

    
    if (d1[dest] != LLONG_MAX && d2[dest] != LLONG_MAX) {
        ans = min(ans, d1[dest] + d2[dest]);
    }

    
    for (int i = 0; i < n; ++i) {
        if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || d3[i] == LLONG_MAX) continue;

        long long total = d1[i] + d2[i] + d3[i];
        ans = min(ans, total);
    }

    return (ans == LLONG_MAX) ? -1 : ans;
}
};

