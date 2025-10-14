class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prev;
        bool skip = false;
        for (int i = 0; i <= n - 2 * k; i++) {
            skip = false;
            prev = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] > prev) {
                    prev = nums[j];
                } else {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                prev = nums[i + k];
                if(k == 1)return true;
                for (int j = i + k + 1; j < i + 2 * k; j++) {
                    if (nums[j] > prev) {
                        prev = nums[j];
                        if (j == i + 2 * k - 1)
                            return true;
                    } else
                        break;
                }
            }
        }
        return false;
    }
};