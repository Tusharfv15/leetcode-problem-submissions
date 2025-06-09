class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>t;
        for(auto it : nums){
            t.push_back(it);
        }
        priority_queue<pair<int,int>>pq;
        pq.push({t[0],0});
        int ans = t[0];

        for(int i = 1;i<n;i++){

            while(!pq.empty() && i - pq.top().second > k){
                pq.pop();
            }
            t[i] = max(t[i],t[i] + pq.top().first);
            pq.push({t[i],i});
            ans = max(ans,t[i]);

        }
       
    return ans;
    }
};