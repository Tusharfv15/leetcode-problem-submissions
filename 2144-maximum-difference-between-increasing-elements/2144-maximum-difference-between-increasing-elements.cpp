class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>suff(n);
        suff[n-1] = nums[n-1];
        int ans = -1;
        for(int i = n-2;i>=0;i--){
            suff[i] = max(suff[i+1],nums[i]);
        }
        for(int i = 0;i<n;i++){
            if(nums[i] == suff[i])continue;
            ans = max(ans,suff[i] - nums[i]);

        }
        return ans;
    }
};