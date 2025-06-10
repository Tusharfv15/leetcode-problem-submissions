class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mpp;
        int maxOddFreq = 0;
        int minEvenFreq = INT_MAX;

        for(auto it : s){
            mpp[it]++;
        }

        for(auto it : mpp){
            if(it.second%2)maxOddFreq = max(it.second,maxOddFreq);
            else minEvenFreq = min(it.second,minEvenFreq);
        }
        return maxOddFreq - minEvenFreq;
    }
};