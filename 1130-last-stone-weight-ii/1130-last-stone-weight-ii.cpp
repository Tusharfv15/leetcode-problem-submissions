class Solution {
    int dp[30][3000];
public:

    int f(int ind,vector<int>&stones,int totSum,int currSum){
        int n = stones.size();
        if(ind == n){
            return abs(2*currSum - totSum);
        }
        if(dp[ind][currSum] !=-1) return dp[ind][currSum];

        int take = f(ind+1,stones,totSum,currSum+stones[ind]);
        int notTake = f(ind+1,stones,totSum,currSum);

        return dp[ind][currSum] = min(take,notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totSum = 0;
        

        for(auto it : stones)totSum+=it;
        memset(dp,-1,sizeof(dp));

        return f(0,stones,totSum,0);
    }
};