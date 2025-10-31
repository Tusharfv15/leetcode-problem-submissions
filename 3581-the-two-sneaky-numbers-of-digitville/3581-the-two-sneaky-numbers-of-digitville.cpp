class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1])ans.push_back(nums[i]);
        }
        return ans;
    }
};