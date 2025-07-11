class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>freeTime;

        freeTime.push_back(startTime[0]);

        for(int i = 1;i<n;i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime[n-1]);
        n = freeTime.size();
        vector<int>maxLeftTime(n,0);
        vector<int>maxRightTime(n,0);

        for(int i = 1;i<n;i++){
            maxLeftTime[i] = max(maxLeftTime[i-1],freeTime[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            maxRightTime[i] = max(maxRightTime[i+1],freeTime[i+1]);
        }

        int ans = 0;

        for(int i = 1;i<n;i++){
            int currEventTime = endTime[i-1] - startTime[i-1];
            if(currEventTime <=max(maxLeftTime[i-1],maxRightTime[i])){
                ans = max(ans,currEventTime+freeTime[i] + freeTime[i-1]);

            }
            ans = max(ans,freeTime[i]+freeTime[i-1]);
        }

        return ans;
    }
};