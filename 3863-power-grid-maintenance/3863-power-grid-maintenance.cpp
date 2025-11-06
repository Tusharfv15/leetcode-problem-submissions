class Solution {
public:
    unordered_map<int,set<int>>mpp;
    
    void dfs(int node,int id,vector<vector<int>>&adjList,vector<int>&vis,vector<int>&storeId){
        vis[node] = 1;
        mpp[id].insert(node);
        storeId[node] = id;
        for(auto it : adjList[node]){
            if(!vis[it]){
                dfs(it,id,adjList,vis,storeId);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        vector<vector<int>>adjList(c+1);
        vector<int>storeId(c+1,0);
        vector<int>ans;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>vis(c+1,0);
        for(int i = 1;i<=c;i++){
            
            if(!vis[i]){
                int id = i;
                dfs(i,id,adjList,vis,storeId);
            }
        }

        for(auto it : queries){
            int status = it[0];
            int node = it[1];
            int id = storeId[node];
            if(status == 2){
                mpp[id].erase(node);

            }
            else if(status == 1){
                if(mpp[id].count(node))ans.push_back(node);
                else mpp[id].empty()?ans.push_back(-1):ans.push_back(*mpp[id].begin());
            }

           
        }
        return ans;


    }
};