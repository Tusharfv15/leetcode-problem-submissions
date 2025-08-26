class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            double maxDiag = 0.0;
            double ans = 0;
        for(auto it : dimensions){
            double len = (double)it[0];
            double wid  =(double)it[1];
            
            double sq = len*len + wid*wid;
            double diag = sqrt(sq);

            if(diag > maxDiag){
                maxDiag = diag;
                ans = len*wid;
            }
            else if(diag == maxDiag){
                    ans = max(ans,len*wid);

            }
        }
        return ans;
    }
};