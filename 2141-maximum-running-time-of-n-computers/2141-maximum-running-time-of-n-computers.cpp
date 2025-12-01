class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);

        long long l = 0, r = sum / n, ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;

            long long total = 0;
            for (long long b : batteries)
                total += min(b, mid);

            if (total >= 1LL * n * mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
