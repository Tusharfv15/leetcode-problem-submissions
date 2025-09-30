class Solution {
public:
    int f(vector<int>&nums,int n){
        if(n == 1)return nums[0];
        vector<int>copy;
        for(int i = 0;i<n-1;i++){
            copy.push_back((nums[i]+nums[i+1])%10);
        }
        return f(copy,n-1);
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        return f(nums,n);
    }
};