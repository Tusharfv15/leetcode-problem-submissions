class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        map<int,int>mpp;
        int ans = INT_MIN;
        for(auto it : nums){
            if(mpp[it] == 0 && ans == INT_MIN){
                    ans = it;
                    mpp[it] = 1;
                }
            else if(mpp[it] == 0 && ans + it > ans ){
                        ans = ans +it;
                        mpp[it] = 1;
                }
                
            else if(mpp[it] == 0 && ans + it < ans){
                return ans;
            }
        }
        return ans;
    }
};