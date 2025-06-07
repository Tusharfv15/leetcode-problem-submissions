class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string,int>mpp;

        for(auto it : words){
            mpp[it]++;
        }

        int ans = 0;
        for(auto it : mpp){
            string revStr = it.first;
            reverse(revStr.begin(),revStr.end());

            if(revStr != it.first && mpp.find(revStr) != mpp.end() ){
                int factor = min(mpp[it.first],mpp[revStr]);
                ans += factor *4;
                mpp[it.first] -= factor;
                mpp[revStr]-=factor;

            }

        }

        bool hasCenter = 0;
        for(auto it : mpp){
            string str = it.first;
            if(str[0] == str[1]){
                int freq = it.second;
                if(freq%2 == 1){
                    hasCenter = 1;
                    ans += (freq-1)*2;
                }
                else {
                    ans += (freq)*2;
                }
            }
        }
        if(hasCenter) return ans +2;
        return ans;
    }
};