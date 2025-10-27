class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int prev = -1;
        int ans = 0;

        for(int i = 0;i<n;i++){
            int curr = 0;
            for(int j = 0;j<m;j++){
                if(bank[i][j] == '1')curr++;
            }
            if(prev !=-1)ans += curr*prev;
           if(curr !=0) prev = curr;
        }
        return ans;
    }
};