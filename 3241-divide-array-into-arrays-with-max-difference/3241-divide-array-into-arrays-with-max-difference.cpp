class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;

        int i = 0;
        while(i <= n-3){
            if(nums[i+1] - nums[i] <=k && nums[i+2] - nums[i+1] <=k && nums[i+2] - nums[i] <=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
                i+=3;
            }
            else i++;
        }
        
        if(ans.size() == n/3) return ans;
        return {};

    }
};