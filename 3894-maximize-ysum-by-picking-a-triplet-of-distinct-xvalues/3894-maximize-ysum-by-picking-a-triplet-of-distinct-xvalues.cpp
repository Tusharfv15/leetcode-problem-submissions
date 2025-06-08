class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        vector<pair<int,int>>storeNum;

        for(int i = 0;i<n;i++){
            storeNum.push_back({y[i],i});
        }
        int ans = 0;
        sort(storeNum.rbegin(),storeNum.rend());
        set<int>st;
        for(auto it : storeNum){
            int num = it.first;
            int ind = it.second;
            if(st.count(x[ind]) == 0){
                ans += num;
                st.insert(x[ind]);
                if(st.size() == 3) break;

            }
        }
        if(st.size() < 3) return -1;
        return ans;
    }
};