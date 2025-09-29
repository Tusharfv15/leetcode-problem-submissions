class Solution {
    int dp[51][51];
public:
    int f(vector<int>&values,int i,int j){
        int ans = INT_MAX;
        if(j - i + 1 < 3) return 0;

        if(dp[i][j] !=-1)return dp[i][j];
        for(int k = i+1;k<j;k++){
            ans = min(ans,values[i]*values[j]*values[k] + f(values,i,k)+f(values,k,j));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp,-1,sizeof(dp));
        return f(values,0,n-1);
    }
};