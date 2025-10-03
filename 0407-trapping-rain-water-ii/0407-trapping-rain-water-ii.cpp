class Solution {
public:
typedef pair<int,pair<int,int>>PP;

    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<PP,vector<PP>,greater<>>pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int col :{0,m-1}){
                pq.push({heightMap[i][col],{i,col}});
                vis[i][col] = 1;
            }
        }
        for(int i = 0;i<m;i++){
            for(int col :{0,n-1}){
                pq.push({heightMap[col][i],{col,i}});
                vis[col][i] = 1;
            }
        }

        int water = 0;
        while(!pq.empty()){
            int ht = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            int r[4] = {-1,0,1,0};
            int c[4] = {0,1,0,-1};

            for(int k = 0;k<4;k++){
                int i_ = i + r[k];
                int j_ = j + c[k];

                if(i_ >=0 && i_<n && j_>=0 && j_ < m && !vis[i_][j_] ){
                    water += max(ht-heightMap[i_][j_],0);
                    pq.push({max(ht,heightMap[i_][j_]),{i_,j_}});
                    vis[i_][j_] = 1;
                }
            }

            
        }
        return water;


    }
};