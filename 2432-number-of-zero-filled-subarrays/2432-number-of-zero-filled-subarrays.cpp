class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int count = 0;
        for(auto it : nums){
            if(it == 0){
                count++;
                ans+=1LL*count;
            }
            else {
                count = 0;
            }
        }
        return ans;
    }
};