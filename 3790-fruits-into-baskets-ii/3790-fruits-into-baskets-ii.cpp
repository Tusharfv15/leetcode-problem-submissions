class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>occupied(n,0);
        for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(!occupied[j] && baskets[j] >= fruits[i]){
                        occupied[j] = 1;
                        break;
                    }
                }
        }
        int ans = 0;
        for(auto it : occupied){
            ans += (it == 0?1:0);
        }
        return ans;
    }
};