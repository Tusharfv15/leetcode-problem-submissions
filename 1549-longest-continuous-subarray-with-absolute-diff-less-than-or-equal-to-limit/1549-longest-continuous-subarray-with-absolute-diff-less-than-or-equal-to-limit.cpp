class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int>st;

        int l = 0;
        int r = 0;
        int ans = 0;

        while(r < n){
            st.insert(nums[r]);
            
            int minEl =*st.begin();
            int maxEl = *st.rbegin();

            while(!st.empty() && abs(maxEl - minEl) > limit){
                st.erase(st.find(nums[l]));
                l++;
               if (!st.empty()) {
                    minEl = *st.begin();
                    maxEl = *st.rbegin();
                }
                
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};