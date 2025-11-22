class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto it : nums){
            if(it%3)ans+=1;

        }
        return ans;
    }
};