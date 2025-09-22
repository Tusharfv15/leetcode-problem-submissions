class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
            maxFreq = max(mpp[it],maxFreq);
        }
        int ans = 0;
        for(auto it : mpp){
            if(it.second == maxFreq)ans+=it.second;
        }
        return ans;
    }
};