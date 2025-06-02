class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipCount = 0;
        int n = nums.size();
        int cnt = 0;

        for(auto it : nums){
            if(it == 0 && cnt%2 == 0){
                cnt++;
            }
            if(it == 1 && cnt%2 == 1){
                cnt++;
            }
        }
        return cnt;

    }
};