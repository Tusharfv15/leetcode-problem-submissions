class Solution {
public:
    vector<long long> dp;

    long long solve(int i, const map<int,int>& mpp, const vector<int>& arr) {
        int n = arr.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int j = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + 3) - arr.begin();
        long long take = 1LL * mpp.at(arr[i]) * arr[i] + solve(j, mpp, arr);
        long long notTake = solve(i + 1, mpp, arr);

        return dp[i] = max(take, notTake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        map<int, int> mpp;
        for (auto x : power) mpp[x]++;

        vector<int> arr;
        for (auto &it : mpp) arr.push_back(it.first);

        dp.assign(arr.size(), -1); // fix here ✅
        return solve(0, mpp, arr);
    }
};
