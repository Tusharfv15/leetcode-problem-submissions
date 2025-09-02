class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];

            for(int j = i+1; j < n; j++){
                int x_ = points[j][0];
                int y_ = points[j][1];
                int cnt = 0;
                bool vis = 0;

                // A = (x, y), B = (x_, y_)
                if(x <= x_ && y >= y_){
                    vis = 1;
                    for(int k = 0; k < n; k++){
                        if(k == i || k == j) continue;
                        int x__ = points[k][0];
                        int y__ = points[k][1];

                        if(x__ >= x && x__ <= x_ && y__ <= y && y__ >= y_){
                            cnt++;
                        }
                    }
                }
                if(vis && cnt == 0) ans++;

                // also check the other way (if j is A and i is B)
                cnt = 0;
                vis = 0;
                if(x_ <= x && y_ >= y){
                    vis = 1;
                    for(int k = 0; k < n; k++){
                        if(k == i || k == j) continue;
                        int x__ = points[k][0];
                        int y__ = points[k][1];

                        if(x__ >= x_ && x__ <= x && y__ <= y_ && y__ >= y){
                            cnt++;
                        }
                    }
                }
                if(vis && cnt == 0) ans++;
            }
        }
        return ans;
    }
};
