class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //Find longest subarray of Unique elements;
        map<int,int>mpp;

        int l = 0;
        int r = 0;

        int sum = 0;
        int ans = 0;
        int n = nums.size();

        while(r < n){
            mpp[nums[r]]++;
            sum+=nums[r];
            while(mpp[nums[r]] >= 2){
                mpp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            ans = max(ans,sum);
            r++;
        }
        return ans;

    }
};