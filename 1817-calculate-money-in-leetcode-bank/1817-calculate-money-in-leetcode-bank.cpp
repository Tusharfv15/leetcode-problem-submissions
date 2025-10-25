class Solution {
public:
    int totalMoney(int n) {
        int ans = 1;       // day 1: deposit 1
        int initial = 0;   // weekly increment
        for (int i = 2; i <= n; i++) {
            if (i % 7 == 1) { // new week starts at day 8, 15, 22, ...
                initial++;
            }
            int val = (i % 7 == 0 ? 7 : i % 7) + initial; // day value
            ans += val;
        }
        return ans;
    }
};
