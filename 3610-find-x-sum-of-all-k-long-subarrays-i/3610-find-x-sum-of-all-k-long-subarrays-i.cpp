class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0;
        int r = k-1;
        unordered_map<int, int> mpp;
        for (int i = 0; i < k; i++) {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        while (r < n) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            
            // Build priority queue for current window
            for (auto it : mpp) {
                int el = it.first;
                int freq = it.second;

                if(pq.size() < x){
                    pq.push({freq, el});
                }
                else if(pq.top().first < freq || (pq.top().first == freq && pq.top().second < el)){
                    pq.pop();
                    pq.push({freq, el});
                }
            }
            
            int sum = 0;
            while (!pq.empty()) {
                sum += pq.top().first * pq.top().second;
                pq.pop();
            }
            ans.push_back(sum);
            
            // Slide window
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
            r++;
            if(r < n) mpp[nums[r]]++;
        }
        return ans;
    }
};