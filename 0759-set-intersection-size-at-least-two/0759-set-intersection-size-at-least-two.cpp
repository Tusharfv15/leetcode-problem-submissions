class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {

        if (a[1] != b[1])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int first = -1;
        int second = -1;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l <= first)continue;
            if(l > second){
                cnt+=2;
                first = r-1;
                second = r;

            }
            else {
                cnt+=1;
                first = second;
                second = r;
                
            }


        }
        return cnt;
    }
};