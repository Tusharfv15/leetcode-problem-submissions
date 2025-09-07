class Solution {
public:
    vector<int> sumZero(int n) {
        int l = n/2;
        vector<int>ans;

        for(int i = -l;i<=l;i++){
            if(n%2 == 0 && i == 0)continue;
            ans.push_back(i);

        }
        return ans;
    }
};