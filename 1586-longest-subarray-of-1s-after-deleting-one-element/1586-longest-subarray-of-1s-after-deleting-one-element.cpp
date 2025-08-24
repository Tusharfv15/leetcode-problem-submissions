class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<int>pref(n,0);
        vector<int>suff(n,0);
        pref[0] = (nums[0] == 1 ? 1: 0);
        suff[n-1] = (nums[n-1] == 1 ? 1: 0);

        for(int i = 1;i<n;i++){
            if(nums[i] == 1)pref[i] = pref[i-1] +1;
            else pref[i] = 0;
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i] == 1)suff[i] = suff[i+1] +1;
            else suff[i] = 0;
        }

        int ans = INT_MIN;
        
        for(int i = 0;i<n;i++ ){
            if(nums[i] == 0){
                if(i == 0)ans=max(ans,suff[i+1]);
                else if(i == n-1)ans=max(ans,pref[i-1]);
                else ans = max(ans,pref[i-1] + suff[i+1]);
            }
        }
        if(ans == INT_MIN) return n-1;
        return ans;
    }
};