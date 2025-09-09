class Solution {
public:
int dp[1001];
    const int mod = 1e9 + 7;
    int solve(int day,int delay,int forget){
        if(day == 1) return 1;
        if(dp[day] !=-1) return dp[day];
        int result  = 0;
        for(int i = day - forget +1;i<=day-delay;i++){
           if(i > 0) result = ((result)%mod +(solve(i,delay,forget))%mod)%mod;
        }

        return dp[day] = result%mod;

    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = n - forget +1;i<=n;i++){
             ans = ((ans)%mod+(solve(i,delay,forget))%mod)%mod;
        }
        return ans;
    }
};