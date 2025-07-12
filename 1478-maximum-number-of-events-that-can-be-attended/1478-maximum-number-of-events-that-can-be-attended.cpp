class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<>>pq;
        int count = 0;
        int currDay = events[0][0];
        int i = 0;
        int n = events.size();
        while(!pq.empty() || i < n){

            while(i < n && events[i][0] == currDay){
                pq.push(events[i][1]);
                i++;
            }

                  while(!pq.empty() && pq.top() < currDay){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                count++;
            }
          
            currDay++;

        }
            return count;
    }
};