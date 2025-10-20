class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        for(auto it : operations){
            if(it[1] == '+')ans++;
            else ans--;
        }
        return ans;
    }
};