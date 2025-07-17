class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int maxDiff = 1000;
        int n = nums.size();
        vector<vector<int>>dp(maxDiff+1,vector<int>(n+1,1));
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = 0 ;j<i;j++){
                int diff = nums[i] - nums[j];
                dp[diff+500][i] = max(dp[diff+500][i],1+dp[diff+500][j]);
                ans = max(ans,dp[diff+500][i]);
            }
        }
        return ans;
    }
};