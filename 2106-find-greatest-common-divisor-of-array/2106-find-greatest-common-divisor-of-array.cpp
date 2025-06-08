class Solution {
public:
    int findGcd(int a,int b){
        while(a > 0 && b > 0){
            if(a>b){
                a = a%b;
            }
            else {
                b = b%a;
            }
        }
        if(a == 0) return b;
        else return a;
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int maxEl = -1e5;
        int minEl = 1e5;
        for(auto it : nums){
            maxEl = max(it,maxEl);
            minEl = min(it,minEl);
        }

        return gcd(maxEl,minEl);
    }
};