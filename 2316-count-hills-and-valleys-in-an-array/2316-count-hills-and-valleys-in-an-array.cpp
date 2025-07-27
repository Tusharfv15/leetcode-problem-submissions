class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n,0);
        vector<int>suff(n,0);

        for(int i = 1;i<n;i++){
            if(nums[i] != nums[i-1])pref[i] = nums[i-1];
            else pref[i] = pref[i-1];
        }

        for(int i = n-2;i>=0;i--){
            if(nums[i] != nums[i+1])suff[i] = nums[i+1];
            else suff[i] = suff[i+1];
        }
        int ans  = 0;
        for(int i = 1;i<n-1;i++){
              if(i > 1 && nums[i] == nums[i-1]) continue;
            

                if (pref[i] == 0 || suff[i] == 0) continue;
                if(nums[i] > pref[i] && nums[i] > suff[i])ans++;
                else if( nums[i] < pref[i] && nums[i] < suff[i])ans++;
        }
        return ans;
    }
};