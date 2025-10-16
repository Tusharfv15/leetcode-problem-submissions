class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        
        for (int it : nums) {
            int mod = ((it % value) + value) % value;
            freq[mod]++;
        }

        int i = 0;
        while (true) {
            int mod = i % value;
            if (freq[mod] == 0) return i;
            freq[mod]--;
            i++;
        }
    }
};
