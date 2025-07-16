class Solution {
public:
    vector<vector<vector<int>>> dp;

    int f(int ind, int prev, int isEven, vector<int>& nums) {
        if (ind == nums.size()) return 0;
        if (dp[ind][prev + 1][isEven] != -1) return dp[ind][prev + 1][isEven];

        int take = 0;
        if(prev == -1 || (prev+nums[ind])%2 == isEven){
            take = 1 + f(ind+1,nums[ind]%2,isEven,nums);
        }
        int notTake = f(ind + 1, prev, isEven, nums);

        return dp[ind][prev + 1][isEven] = max(take, notTake);
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return max(f(0, -1, 0, nums), f(0, -1, 1, nums));
    }
};