class Solution {
public:
    int f(int ind,int currOr,vector<int>&nums,int maxOr){
        int n = nums.size();
    if(ind == n){
        if(currOr == maxOr) return 1;
        return 0;
    };
    int notTake  = f(ind+1,currOr,nums,maxOr);
    int newOr = currOr|nums[ind];
    int take = f(ind+1,newOr,nums,maxOr);

    return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size();
        int maxOr = 0;

        for(auto it : nums){
            maxOr = maxOr | it;
        }

        return f(0,0,nums,maxOr);
    }
};