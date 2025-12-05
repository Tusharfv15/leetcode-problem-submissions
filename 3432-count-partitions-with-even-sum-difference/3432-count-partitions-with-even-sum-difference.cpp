class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        int suffSum = 0;
        int preSum = 0;
        int idx = 0;
        int n = nums.size();
        for(auto it : nums){
            if(idx == n-1)continue;
            preSum += it;
            suffSum = sum - preSum;
            if((preSum - suffSum)%2 == 0)ans++;
            idx++;
        }
        return ans;
    }
};