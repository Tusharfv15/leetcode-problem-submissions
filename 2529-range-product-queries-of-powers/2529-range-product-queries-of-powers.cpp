class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Modular exponentiation (your style but with %MOD)
    long long mod_pow(long long x, long long n) {
        long long ans = 1;
        while (n) {
            if (n % 2) {
                ans = (__int128)ans * x % MOD;
                n--;
            } else {
                x = (__int128)x * x % MOD;
                n /= 2;
            }
        }
        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int nCopy = n, powBit = 0;

        // Extract powers of two from n
        while (nCopy) {
            if (nCopy & 1) {
                long long exp = 1LL << powBit;
                powers.push_back(exp % MOD);
            }
            nCopy >>= 1;
            powBit++;
        }

        // Prefix product mod MOD
        int m = powers.size();
        vector<long long> storeProduct(m);
        storeProduct[0] = powers[0];
        for (int i = 1; i < m; i++) {
            storeProduct[i] = (storeProduct[i - 1] * powers[i]) % MOD;
        }

        // Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int i = q[0], j = q[1];
            long long rangeProduct;
            if (i > 0) {
                // Modular inverse using Fermat's theorem
                long long inv = mod_pow(storeProduct[i - 1], MOD - 2);
                rangeProduct = (storeProduct[j] * inv) % MOD;
            } else {
                rangeProduct = storeProduct[j];
            }
            ans.push_back((int)rangeProduct);
        }

        return ans;
    }
};
