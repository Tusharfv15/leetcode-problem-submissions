class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        map<int, int> mpp;
        for (auto x : power) mpp[x]++;

        vector<int> arr;
        for (auto &it : mpp) arr.push_back(it.first);
        int n = arr.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // find the first index j such that arr[j] >= arr[i] + 3
            int j = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + 3) - arr.begin();

            long long take = 1LL * mpp[arr[i]] * arr[i] + dp[j];
            long long notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};
