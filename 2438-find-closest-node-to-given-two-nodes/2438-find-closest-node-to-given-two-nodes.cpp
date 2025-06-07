class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&dist,int start){
        queue<int>q;
        dist[start] = 0;;
        int n = dist.size();
        vector<int>vis(n,0);
        vis[start] = 1;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    dist[it] = dist[node]+1;
                    vis[it] = 1;
                }
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
            int n = edges.size();
            vector<vector<int>>adj(n);

            for(int i = 0;i<n;i++){
               if(edges[i] !=-1) adj[i].push_back(edges[i]);
            }

            vector<int>dist1(n,INT_MAX);
            vector<int>dist2(n,INT_MAX);

            bfs(adj,dist1,node1);
            bfs(adj,dist2,node2);
            int ans = -1;
            int minDist = INT_MAX;
            //int maxDist = 0;
            for(int i = 0;i<n;i++){
                  if(dist1[i] != INT_MAX && dist2[i] != INT_MAX){int maxDist = max(dist1[i],dist2[i]);
                  if(maxDist < minDist){
                    minDist = maxDist;
                    ans = i;
                  }
                  }
                    
            }
            //if(ans == INT_MAX) return -1;
            return ans;
        




    }
};