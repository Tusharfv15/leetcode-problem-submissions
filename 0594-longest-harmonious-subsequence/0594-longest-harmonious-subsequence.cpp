class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int l = 0;
        int ans = 0;
        int r = 1;
        sort(nums.begin(),nums.end());
        while(r < n){
            while(l < r && abs(nums[r] - nums[l]) > 1){
                l++;
            }
            if(nums[r] - nums[l] == 1)ans = max(ans,r-l+1);
            r++;

        }
        return ans;
    }
};