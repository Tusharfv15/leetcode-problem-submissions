class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < n){
            while(j < n && nums[j] - nums[i] <= k ){
                j++;
            }
            ans++;
            i = j;

        }
        return ans;
    }
};