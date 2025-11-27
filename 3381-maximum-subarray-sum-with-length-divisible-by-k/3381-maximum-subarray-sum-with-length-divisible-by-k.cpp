class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix[0] = 1LL*nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = 1LL*prefix[i-1]+ 1LL*nums[i];
        }
        long long ans = LLONG_MIN;
        for(int start = 0;start < k;start++){
            long long currSum = 0;
            int i = start;
            while(i < n && i + k -1 < n){
                int j = i + k-1;
                long long subSum = prefix[j] - (i-1>=0?prefix[i-1]:0);
                currSum = max(subSum,currSum+subSum);
                ans = max(currSum,ans);
                i += k;

            }
        }
        return ans;
    }
};