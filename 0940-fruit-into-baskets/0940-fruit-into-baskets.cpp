class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;

        int l = 0;
        int r = 0;
        int ans  = 0;
        while(r < n){
            mpp[nums[r]]++;

            while(mpp.size() >2){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0)mpp.erase(nums[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};