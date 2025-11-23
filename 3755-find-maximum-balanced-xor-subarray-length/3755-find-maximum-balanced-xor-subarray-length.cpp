class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> evenCount(n, 0);

        evenCount[0] = (nums[0] % 2 == 0);
        for (int i = 1; i < n; i++)
            evenCount[i] = evenCount[i - 1] + (nums[i] % 2 == 0);

        int xr = 0, ans = 0;
        map<pair<int, int>, int> mpp;

        mpp[{0, 0}] = -1;  

        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            
            int evens = evenCount[i];
            int odds = (i + 1) - evens;
            int diff = odds - evens;
            
            pair<int, int> key = {xr, diff};
            
            if (mpp.find(key) != mpp.end()) {
                ans = max(ans, i - mpp[key]);
            } else {
                mpp[key] = i;
            }
        }

        return ans;
    }
};