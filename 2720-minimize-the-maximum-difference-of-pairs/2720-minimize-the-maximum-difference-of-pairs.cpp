class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int p){
        int i = 0;
        int cnt = 0;
        while(i < nums.size()-1){
            if(nums[i+1] - nums[i] <=mid){
                cnt++;
                i+=2;
            }
            else {
                i+=1;
            }
        }
        return cnt >=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[n-1];
        int result = INT_MAX;
        while(l <=r){
            int mid = (r+l)/2;

            if(isValid(nums,mid,p)){
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return result;
    }
};