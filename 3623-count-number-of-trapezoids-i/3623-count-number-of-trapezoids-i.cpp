class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long ans = 0;
        int mod = 1e9 + 7;
        unordered_map<long long, long long> mpp;

        for (auto &it : points) {
            mpp[(long long)it[1]]++;
        }

        long long totPos = 0;
        for (auto &it : mpp) {
            long long n = it.second;
            totPos += (n * (n - 1)) / 2LL;  
        }

        for (auto &it : mpp) {
            long long cnt = it.second;
            long long pos = (cnt*(cnt-1))/2LL;
            ans += pos * (totPos - pos);
        }

        ans = ans / 2;  

       
        ans %= mod;
        //if (ans < 0) ans += mod;

        return (int)ans;
    }
};
