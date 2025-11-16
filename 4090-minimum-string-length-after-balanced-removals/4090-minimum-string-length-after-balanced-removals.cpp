class Solution {
public:
    int minLengthAfterRemovals(string s) {
       int aCount = 0;
       int bCount = 0;

       for(auto it : s){
        if(it == 'a')aCount++;
        else bCount++;
       }

       return abs(aCount-bCount);
    }
};