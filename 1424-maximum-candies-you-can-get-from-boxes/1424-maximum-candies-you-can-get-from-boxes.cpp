class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        for(auto it : initialBoxes)q.push(it);
        int ans = 0;
        while(!q.empty()){
            int box = q.front();
            q.pop();

            if(status[box] == 0){
                if(q.empty()) return ans;
                else q.push(box);
            }
            else {
                ans += candies[box];

                for(auto key : keys[box]){
                    status[key] = 1;
                }

                for(auto it : containedBoxes[box]){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};