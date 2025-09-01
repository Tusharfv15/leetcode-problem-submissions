struct cmp {
    bool operator()(const pair<double,pair<int,int>>&a, const pair<double,pair<int,int>>&b) {
        double aRatio = (double)(a.second.first+1) / (double)(a.second.second+1);
        double bRatio = (double)(b.second.first+1) / (double)(b.second.second+1);

        double aChange = aRatio - a.first;
        double bChange = bRatio - b.first;

        return aChange < bChange;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, cmp> pq;

        for (auto it : classes) {
            int i = it[0];
            int j = it[1];
            double ratio = (double)i / (double)j;

            pq.push({ratio,{i,j}});
        }

        for (int i = 0; i < extraStudents; i++) {
            if (!pq.empty()) {
                double ratio = pq.top().first;
                int a = pq.top().second.first;
                int b = pq.top().second.second;

                pq.pop();

                double newRatio = (double)(a+1) / (double)(b+1);
                pq.push({newRatio,{a+1,b+1}});
            }
        }

        double ans = 0;

        while (!pq.empty()) {
            ans += pq.top().first;
            pq.pop();
        }
        return ans / n;
    }
};
