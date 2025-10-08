class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i = 0;i<n;i++){
            long long num = spells[i];
            long long limit = (success + num - 1) / num;


            auto it = lower_bound(potions.begin(),potions.end(),limit);
            if(it == potions.end())ans.push_back(0);
            else ans.push_back(potions.end() - it);

        }
        return ans;
    }
};