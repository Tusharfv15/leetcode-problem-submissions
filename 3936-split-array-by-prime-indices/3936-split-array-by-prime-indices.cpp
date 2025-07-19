class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        // 2 *sumPrimes - totSum;
        
        vector<int>isPrime(n,1);
        isPrime[0] = 0;
        if(n>1)isPrime[1] = 0;
        for(int p = 2;p*p<n;p++){
            if(isPrime[p]){
                for(int i = p*p;i<n;i+=p){
                    isPrime[i] = 0;
                }
            }
        }
        long long totSum = 0;

        for(auto it : nums){
            totSum+=it;
        }
        long long sumPrimes = 0;
        for(int i = 0;i<n;i++){
            if(isPrime[i])sumPrimes+=nums[i];
        }
        return abs(2*sumPrimes - totSum);

    }
};