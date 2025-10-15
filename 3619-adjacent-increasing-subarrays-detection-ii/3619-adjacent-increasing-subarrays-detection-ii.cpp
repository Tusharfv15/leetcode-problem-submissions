class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int currRun = 1;
        int prevRun = 0;
        int ans = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }
            else {
                prevRun = currRun;
                currRun  = 1;
            }

            ans  = max(ans,min(prevRun,currRun));
            ans = max(ans,currRun/2);
            
        }

        return ans;
    }
};