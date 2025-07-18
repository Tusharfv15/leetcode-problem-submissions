class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        priority_queue<int> maxHeap;
        long long lSum = 0;
        vector<long long> lMinSum(N, 0);
        vector<long long> rMaxSum(N, 0);

        for (int i = 0; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            lSum += nums[i];

            if (maxHeap.size() > n) {
                lSum -= maxHeap.top();
                maxHeap.pop();
            }
            lMinSum[i] = lSum;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rSum = 0;

        for (int i = N - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            rSum += nums[i];

            if (minHeap.size() > n) {
                rSum -= minHeap.top();
                minHeap.pop();
            }
            rMaxSum[i] = rSum;
        }

        long long result = LLONG_MAX;

        for (int i = n - 1; i <= 2 * n - 1; i++) {
            result = min(result, lMinSum[i] - rMaxSum[i + 1]);
        }

        return result;
    }
};
