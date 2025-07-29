class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>setBit(32,-1);
        vector<int>result(n);
        for(int i = n-1;i>=0;i--){
            int endIndex = i;
            for(int j = 0;j<32;j++){
                if(!(nums[i] & (1 << j))){ // jth bit notSet
                        if(setBit[j] !=-1){
                                endIndex = max(endIndex,setBit[j]);
                        }
                }
                else {
                        setBit[j] = i;
                }
            }
            result[i] = endIndex - i +1;
        }
        return result;
    }
};