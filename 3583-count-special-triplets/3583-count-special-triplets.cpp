class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (int i = 1; i < n - 1; i++) {
            int el = 2 * nums[i];
            int freq = mpp[el].size();
            if (freq == 0)
                continue;
            int it = lower_bound(mpp[el].begin(), mpp[el].end(), i) -
                     mpp[el].begin();

            if (it == freq)
                continue;

            int leftFreq = it;
            int rightFreq = freq - it;
            if (nums[i] == 0)
                rightFreq--;

            if (rightFreq < 0)
                continue;
            ans = (ans + 1LL * leftFreq * rightFreq) % mod;

        }
        return ans;
    }
};