class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        vector<bool>ans;
        for(int i = 0;i<n;i++){
            curr = (2*curr + nums[i])%5;
            ans.push_back(curr == 0);
        }
        return ans;
    }
};