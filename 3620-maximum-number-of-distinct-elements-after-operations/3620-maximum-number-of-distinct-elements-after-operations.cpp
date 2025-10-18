class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        int count = 0;
        for(int i = 0;i<n;i++){
            int minVal = nums[i] - k;
                if(prev < minVal ){
                    prev = minVal;
                    count++;
                }
                else if(prev+1 <= nums[i] + k){
                    prev+=1;
                    count++;
                }
        }
        return count;
    }
};