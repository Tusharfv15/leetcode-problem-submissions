class Solution {
public:
    unordered_map<int, pair<int, int>> mpp;

    int f(int ind, int m, int n, vector<string>& strs,vector<vector<vector<int>>>&dp) {
        if (ind == strs.size())
            return 0;
            if(dp[ind][m][n] !=-1)return dp[ind][m][n];
        string str = strs[ind];
        int zeroCount = mpp[ind].first;
        int oneCount = mpp[ind].second;
        int take = INT_MIN;
        if (m - zeroCount >= 0 && n - oneCount >= 0) {
            take = 1 + f(ind + 1, m - zeroCount, n - oneCount, strs,dp);
        }
        int notTake = f(ind + 1, m, n, strs,dp);

        return dp[ind][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int n_ = strs.size();

        vector<vector<vector<int>>> dp(
            n_ + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        for (int i = 0; i < n_; i++) {
            for (auto it : strs[i]) {
                if (it == '0')
                    mpp[i].first++;
                else
                    mpp[i].second++;
            }
        }
        return f(0, m, n, strs,dp);
    }
};