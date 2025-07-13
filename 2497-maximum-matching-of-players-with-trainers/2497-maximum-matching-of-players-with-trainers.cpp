class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < m){
            while(j < m && players[i] > trainers[j]){
                j++;
            }
           if(j < m) ans++;
            j++;
            i++;
        }
            return ans;
    }
};