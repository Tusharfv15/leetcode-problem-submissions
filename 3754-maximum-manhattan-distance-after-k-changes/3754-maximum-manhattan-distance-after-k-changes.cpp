class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0;
        int maxDist = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N') y++;
             if (s[i] == 'S') y--;
            if (s[i] == 'E') x++;
             if (s[i] == 'W') x--;


            int md = abs(x) + abs(y);
            int currDist = md + min(2*k,i+1-md);
            maxDist = max(maxDist, currDist);
        }

        return maxDist;
    }
};
