class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int>maxq;
        deque<int>minq;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < n){
            while(!maxq.empty() && maxq.back() < nums[r])maxq.pop_back();
            while(!minq.empty() && minq.back() > nums[r])minq.pop_back();
            maxq.push_back(nums[r]);
            minq.push_back(nums[r]);

            while(maxq.front() - minq.front() > limit){
                if(maxq.front() == nums[l])maxq.pop_front();
                if(minq.front() == nums[l])minq.pop_front();
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};