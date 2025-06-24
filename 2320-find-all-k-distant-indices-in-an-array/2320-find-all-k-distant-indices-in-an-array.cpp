class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>index;
        set<int>st;
        for(int i = 0;i<n;i++){
            if(nums[i] == key)index.push_back(i);
        }

        for(int i = 0;i<index.size();i++){
            int ind = index[i];

            for(int j = 0;j<n;j++){
                    if(abs(j - ind) > k) continue;
                    st.insert(j);
            }
        }
        vector<int>ans(st.begin(),st.end());

        return ans;
    }
};