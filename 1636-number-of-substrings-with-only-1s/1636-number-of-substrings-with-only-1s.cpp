class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        int r = 0;
       
        
                while (r < n) {
            if (s[r] == '0') {
                while (r < n && s[r] == '0') {
                    r++;
                }
                l = r;
            } else {
                ans = (ans + ((r - l + 1))%mod)%mod;
                r++;
            }
        }
        return ans%mod;
    }
};