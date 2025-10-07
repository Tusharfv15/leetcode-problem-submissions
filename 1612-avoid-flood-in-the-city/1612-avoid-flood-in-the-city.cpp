class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>mpp;
        set<int>st;
        
        int n = rains.size();
        vector<int>ans(n,1);

        for(int i = 0;i<n;i++){
            int lake = rains[i];
            if(lake == 0){
                st.insert(i);
            }
            else {
                ans[i] = -1;
                if(mpp.count(lake)){
                    auto it = st.lower_bound(mpp[lake]);

                    if(it == st.end())return {};

                    int day = *it;
                    ans[day] = lake;
                    st.erase(it);
                }
                mpp[lake] = i;
            }
            
            
        }
        return ans;
    }
};