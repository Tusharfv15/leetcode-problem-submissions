class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int best = 0;
        for(int i = 0; i < n; i++){
            long long th = (long long)nums[i] * k;
            
            int l = i;
            int r = n - 1;
            int ans = i;
            
            while(l <= r){
                int mid = (l + r) / 2;
                if(nums[mid] <= th){
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            
            best = max(best, ans - i + 1);
        }
        return n - best;
    }
};