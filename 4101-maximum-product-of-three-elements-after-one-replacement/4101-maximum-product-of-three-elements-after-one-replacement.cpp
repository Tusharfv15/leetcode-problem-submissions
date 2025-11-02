class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < 0)nums[i] = -nums[i];
        }
        sort(nums.begin(),nums.end());
        

        return 1LL*1e5*1LL*nums[n-2]*1LL*nums[n-1];


    }
};