class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_el = *max_element(nums.begin(),nums.end());
        int len = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            
            if(nums[i] == max_el){
                len++;
            }
            else{
                ans = max(ans,len);
                len = 0;
            }
        }
        ans = max(ans,len);

        return ans;

    }
};