class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflictingPoints(n+1);
        for (auto it : conflictingPairs) {
            int a = min(it[0], it[1]);
            int b = max(it[0], it[1]);
            conflictingPoints[b].push_back(a);
        }

        long long valid = 0;
        int maxC = 0;
        int secondMaxC = 0;
        vector<long long> extra(n+1, 0);

        for (int end = 1; end <= n; end++) {
            for (auto it : conflictingPoints[end]) {
                if (it >= maxC) {
                    secondMaxC = maxC;
                    maxC = it;
                } else if (it > secondMaxC) {
                    secondMaxC = it;
                }
            }
            valid += end - maxC;
            extra[maxC] += maxC - secondMaxC;
        }

        return valid + *max_element(extra.begin(), extra.end());
    }
};
