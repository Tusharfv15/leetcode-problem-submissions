class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end()) + k;

        vector<int> storeFreq(maxEl + 1, 0);
        for (auto it : nums) storeFreq[it]++;
        for (int i = 1; i <= maxEl; i++) storeFreq[i] += storeFreq[i - 1];

        int ans = 0;
        for (int i = 0; i <= maxEl; i++) {
            if (storeFreq[i] == 0) continue;
            int left = max(0, i - k);
            int right = min(maxEl, i + k);

            int total = storeFreq[right] - (left > 0 ? storeFreq[left - 1] : 0);
            int targetCount = storeFreq[i] - (i - 1 >= 0 ? storeFreq[i - 1] : 0);

            int needConversion = total - targetCount;
            int pos = targetCount + min(needConversion, numOperations);
            ans = max(ans, pos);
        }

        return ans;
    }
};
