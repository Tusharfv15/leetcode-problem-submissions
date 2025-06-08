class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        vector<string>Stringans;
        for(int i = 1;i<=n;i++){
            string num = to_string(i);
            Stringans.push_back(num);
        }
        sort(Stringans.begin(),Stringans.end());
        for(auto it : Stringans){
            int num = stoi(it);
            ans.push_back(num);
        }
        return ans;
    }
};