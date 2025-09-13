class Solution {
public:
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxCons = 0;

        map<char,int>mpp;

        for(auto it : s){
            if(it == 'a' ||it == 'e' ||it == 'i' ||it == 'o' ||it == 'u'){
                mpp[it]++;
                maxVow = max(maxVow,mpp[it]);
            }
            else {
                mpp[it]++;
                maxCons = max(maxCons,mpp[it]);
            }
        }
        return maxVow+maxCons;
    }
};