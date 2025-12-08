class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                double c = sqrt(i * i + j * j);
                int d = sqrt(i*i+j*j);
                if (c-d ==0 && d <= n)
                    ans++;
            }
        }
        return ans;
    }
};