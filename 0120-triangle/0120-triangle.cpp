class Solution {
public:
    int dp[201][201];

    int f(int i, int j, const vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j];
        if (dp[i][j] != INT_MIN) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        return f(0, 0, triangle);
    }
};
