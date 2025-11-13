class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int oneCount = 0;
        int i = 0;
        int ans = 0;
        while(i < n){
            if(s[i] == '1'){
                oneCount++;
                i++;
            }
            else if(s[i] == '0'){
                ans += oneCount;
                while(i < n && s[i] == '0')i++;
            }
        }
        return ans;
    }
};