class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        int i = 0;
        int ans = 0;
        while (i < n) {
            while (pq.empty() || pq.top().second == colors[i]) {
                pq.push({neededTime[i], colors[i]});
                i++;
            }

            if (pq.size() == 1) {
                pq.pop();
                continue;
            } else if (pq.size() >= 2) {
                int m = pq.size();
                int sum = 0;
                while (m - 1) {
                    sum += pq.top().first;
                    pq.pop();
                    m--;
                }
                ans += sum;
                pq.pop();
            }
        }

        if (pq.size() >= 2) {
            int m = pq.size();
            int sum = 0;
            while (m - 1) {
                sum += pq.top().first;
                pq.pop();
                m--;
            }
            ans +=sum;
            pq.pop();
        }

       
        return ans;
    }
};