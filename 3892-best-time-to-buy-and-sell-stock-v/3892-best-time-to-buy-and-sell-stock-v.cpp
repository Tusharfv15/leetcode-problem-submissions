class Solution {
     const long long mn = -1e14;
public:
    long long f(int ind,int k,int holdType,vector<int>&prices,int n,vector<vector<vector<long long>>>&dp){
            if(ind == n){
                if(holdType == 0) return 0;
                return -1e14;
            }

            if(dp[ind][k][holdType] != mn) return dp[ind][k][holdType];
        long long normalTransaction = -1e9;
        long long shortTransaction = -1e9;
        long long noTransaction = -1e9;
        if(holdType == 0){
            normalTransaction = -prices[ind] + f(ind+1,k,1,prices,n,dp);
            shortTransaction = prices[ind] + f(ind+1,k,2,prices,n,dp);

        }
        else if( k > 0){
            if(holdType == 1){
                normalTransaction = prices[ind] + f(ind+1,k-1,0,prices,n,dp);

            }
            else {
                shortTransaction = -prices[ind] + f(ind+1,k-1,0,prices,n,dp);
            }
        }
        noTransaction = f(ind+1,k,holdType,prices,n,dp);

        return dp[ind][k][holdType] = max({normalTransaction,shortTransaction,noTransaction});

    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        int kSize= (n/2) + 2;
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(kSize,vector<long long>(3,mn)));

        return f(0,k,0,prices,n,dp);
    }
};