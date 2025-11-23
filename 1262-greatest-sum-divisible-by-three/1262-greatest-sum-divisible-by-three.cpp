class Solution {
public:
    int f(int ind, int n, vector<int>& nums, int mod,vector<vector<int>>&dp) {
        if (ind == n) {
            if (mod == 0)
                return 0;
            return INT_MIN;
        }
        if(dp[ind][mod+1] !=-1)return dp[ind][mod+1];
        int notTake = f(ind + 1, n, nums, mod,dp);
        int take = 0;

        if (mod == -1)
            take = nums[ind] + f(ind + 1, n, nums, nums[ind] % 3,dp);
        else {
            int newMod = (mod + nums[ind]) % 3;
            take = nums[ind] + f(ind + 1, n, nums, newMod,dp);
        }
        return dp[ind][mod+1] = max(take, notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        int res = f(0, n, nums, -1,dp);

        if (res <= 0)
            return 0;
        return res;
    }
};