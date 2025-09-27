class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = -1e9;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){

                    if(i == j || j == k || k == i)continue;
                    double x1 = points[i][0];
                    double y1 = points[i][1];

                    double x2 = points[j][0];
                    double y2 = points[j][1];

                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    
                    double area = 0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                    ans = max(ans,area);

                }

            }
        }
        return ans;
    }
};