class Solution {
public:
    int f(int ind, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return currOr == maxOr ? 1 : 0;

        if (dp[ind][currOr] != -1) return dp[ind][currOr];

        int notTake = f(ind + 1, currOr, nums, maxOr, dp);
        int take = f(ind + 1, currOr | nums[ind], nums, maxOr, dp);

        return dp[ind][currOr] = take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (auto x : nums) maxOr |= x;

        
        vector<vector<int>> dp(n + 1, vector<int>(maxOr+1, -1));

        return f(0, 0, nums, maxOr, dp);
    }
};
