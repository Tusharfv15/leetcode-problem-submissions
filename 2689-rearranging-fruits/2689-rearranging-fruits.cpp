class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> totalCounts;

        for (auto it : basket1) totalCounts[it]++;
        for (auto it : basket2) totalCounts[it]--;

        long long minVal = LLONG_MAX;
        for (int x : basket1) minVal = min(minVal, 1LL * x);
        for (int x : basket2) minVal = min(minVal, 1LL * x);

        for (auto it : totalCounts) {
            if (it.second % 2) return -1; // Odd imbalance → impossible
        }

        vector<long long> fruits_to_swap;
        for (auto it : totalCounts) {
            int numFruits = abs(it.second);
            for (int i = 0; i < numFruits / 2; i++) {
                fruits_to_swap.push_back(it.first);
            }
        }

        sort(fruits_to_swap.begin(), fruits_to_swap.end());

        long long totCost = 0;
        int swaps = fruits_to_swap.size() / 2;
        for (int i = 0; i < swaps; ++i) {
            totCost += min(fruits_to_swap[i], 2 * minVal);
        }

        return totCost;
    }
};
