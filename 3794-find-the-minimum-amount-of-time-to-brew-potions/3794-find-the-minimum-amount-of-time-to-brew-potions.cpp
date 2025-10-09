class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {
        int n = skills.size();
        int m = mana.size();
        vector<long long>finishTime(n,0);

        for(int j = 0;j<m;j++){
            finishTime[0]+=mana[j]*skills[0];
            for(int i = 1;i<n;i++){
                finishTime[i] = max(finishTime[i-1],finishTime[i])+1LL*mana[j]*skills[i];
            }

            for(int i = n-1;i>=1;i--){
                finishTime[i-1] = finishTime[i] - 1LL*mana[j]*skills[i];
            }
        }
        return finishTime[n-1];
    }
};