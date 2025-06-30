class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mpp;

        for(auto it : nums){
            mpp[it]++;
        }
        int ans = 0;
        for(auto it : mpp){
            int num = it.first;
            int freq = it.second;
            if(mpp.count(num+1)){
                int len = freq + mpp[num+1];
                ans = max(ans,len);
            }
        }
        return ans;
    }
};