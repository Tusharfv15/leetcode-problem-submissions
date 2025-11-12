class Solution {
public:
    int findgcd(int a, int b) { 
        while (a > 0 && b > 0) { if (a > b) { a = a % b; } else { b = b % a; } } if (a == 0) return b; else return a; }
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
                count1++;
        }

        if(count1 > 0) {
            return n - count1;
        }

        int minStepsTo1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            int GCD = nums[i];
            for(int j = i+1; j < n; j++) {
                GCD = findgcd(GCD, nums[j]);
                
                if(GCD == 1) {
                    minStepsTo1 = min(minStepsTo1, j-i);
                    break;
                }
            }
        }

        if(minStepsTo1 == INT_MAX) {
            return -1;
        }
        return minStepsTo1 + (n-1);
    }
};