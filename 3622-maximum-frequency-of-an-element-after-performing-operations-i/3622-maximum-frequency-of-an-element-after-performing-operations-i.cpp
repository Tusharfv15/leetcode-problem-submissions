class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(),nums.end())+k;

        map<int,int>freq;
        map<int,int>diff;

        for(auto it : nums){
            freq[it]++;
            int l = max(it-k,0);
            int r = min(it+k,maxEl);

            diff[l]++;
            diff[r+1]--;

            diff[it]+=0;
        }

        int result = 0;
        int cumSum = 0;
        for(auto it : diff){
            int target = it.first;
            cumSum += it.second;

            int targetFreq = freq[target];
            int need = cumSum - targetFreq;

            int res = min(need,numOperations);

            result = max(result,res+targetFreq);
        }
        return result;
    }
};