class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0;
        int rCount = 0;
        bool stationary = false;
        int ans = 0;

        while (i < n) {
            if (directions[i] == 'R') {
                rCount++;
                i++;
            } else if (directions[i] == 'L') {
                if (rCount > 0) {
                    ans += rCount + 1;
                    rCount = 0;
                    stationary = true;
                } else if (stationary) {
                    ans++;
                }
                i++;
            } else {
                if (rCount > 0) {
                    ans += rCount;
                    rCount = 0;
                }
                stationary = true;
                i++;
            }
        }

        return ans;
    }
};
