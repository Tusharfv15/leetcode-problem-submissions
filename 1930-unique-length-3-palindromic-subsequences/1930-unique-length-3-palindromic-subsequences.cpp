class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        
        for(int i = n-1; i >= 0; i--){
            if(last[s[i] - 'a'] == -1) {
                last[s[i] - 'a'] = i;
            }
        }
        
        // pref[i][c] = number of times character c appears from index 0 to i
        vector<vector<int>> pref(n, vector<int>(26, 0));
        pref[0][s[0] - 'a'] = 1;
        
        for(int i = 1; i < n; i++){
            for(int c = 0; c < 26; c++){
                pref[i][c] = pref[i-1][c];
            }
            pref[i][s[i] - 'a']++;
        }
        
        int ans = 0;
        vector<int> vis(26, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[s[i] - 'a']){
                int rightMost = last[s[i] - 'a'];
                if(rightMost != -1 && rightMost > i + 1){
                    // Count how many unique characters exist between i and rightMost
                    int uniqueCount = 0;
                    for(int c = 0; c < 26; c++){
                        int countBetween = pref[rightMost-1][c] - pref[i][c];
                        if(countBetween > 0) uniqueCount++;
                    }
                    ans += uniqueCount;
                    vis[s[i] - 'a'] = 1;
                }
            }
        }
        
        return ans;
    }
};