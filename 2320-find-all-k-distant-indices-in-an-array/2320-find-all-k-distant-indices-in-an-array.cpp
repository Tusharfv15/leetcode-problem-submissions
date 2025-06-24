class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int>ans;
        int right = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] == key){
                int left = max(right,i-k);
                right = min(n,i+k+1);
                for(int j = left;j<right;j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};