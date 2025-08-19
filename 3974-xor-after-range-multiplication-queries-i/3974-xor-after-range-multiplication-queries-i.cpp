class Solution {
public:
const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();


        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            while(l <= r){
                long long num = (1LL*(nums[l]%mod)*(v%mod))%(mod);
                nums[l] = num;
                l += k;

            }
            
        }
        int ans = 0;
        for(auto it : nums)ans ^= it;

        return ans;

    }
};