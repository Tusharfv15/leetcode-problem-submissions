class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int k = sum % p;
        if (k == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;  

        long long pre = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            pre = (pre + nums[i]) % p;

            int rem = (pre - k + p) % p;

            if (mpp.count(rem)) {
                ans = min(ans, i - mpp[rem]);
            }

            mpp[pre] = i;
        }

        return ans == n || ans == INT_MAX ? -1 : ans;
    }
};
