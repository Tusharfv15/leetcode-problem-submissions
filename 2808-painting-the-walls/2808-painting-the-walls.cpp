class Solution {
    
public:
    int dp[505][505];
    int f(int ind,int n,vector<int>&cost,vector<int>&time){
        int sz = cost.size();
        if(n <=0) return 0;
        if(ind == sz){
            if(n == 0) return 0;
            return 1e9+7;
        }
        if(dp[ind][n] !=-1) return dp[ind][n];

        int paidPainter = cost[ind] + f(ind+1,n-1-time[ind],cost,time);
        int notTake = f(ind+1,n,cost,time);

        return dp[ind][n] = min(paidPainter,notTake);

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n,cost,time);
    }
};