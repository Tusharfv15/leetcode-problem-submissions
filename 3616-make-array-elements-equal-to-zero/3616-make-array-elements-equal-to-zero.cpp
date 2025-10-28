class Solution {
public:
    int f(int i,vector<int>&nums,int dir){
        if(i < 0 || i >= nums.size()){
            for(auto it :nums ){
                if(it !=0)return 0;
            }
            return 1;
        }

        if(nums[i] == 0) return f(i+dir,nums,dir);

        else {
            nums[i]--;
            
            return f(i-dir,nums,-dir);
        }
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                vector<int> temp = nums;
                ans += f(i+1,temp,1);
                temp = nums;
                ans += f(i-1,temp,-1);
            }
        }
        return ans;
    }
};