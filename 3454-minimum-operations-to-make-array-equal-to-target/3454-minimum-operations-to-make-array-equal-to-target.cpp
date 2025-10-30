class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> diff;
        for (int i = 0; i < nums.size(); i++) {
            diff.push_back(nums[i] - target[i]);
        }

        int n = nums.size();
        int prev = diff[0];
        long long ans = abs(prev);

        for (int i = 1; i < n; i++) {
            int curr = diff[i];

            // if sign flips, start a new segment
            if ((prev < 0 && curr > 0) || (prev > 0 && curr < 0)) {
                ans += abs(curr);
            }
            // if same sign and magnitude increases
            else if ((prev >= 0 && curr >= 0) || (prev <= 0 && curr <= 0)) {
                if (abs(curr) > abs(prev)) {
                    ans += abs(curr) - abs(prev);
                }
            }

            prev = curr;
        }
        return ans;
    }
};
