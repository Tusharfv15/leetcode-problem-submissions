class Solution {
public:
    int dp[201][201];

    int f(int i, int j, vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int op1 = triangle[i][j];
        int op2 = triangle[i][j];

        op1 += f(i + 1, j, triangle);
        op2 += f(i + 1, j + 1, triangle);

        return dp[i][j] = min(op1, op2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = -1;
            }
        }
        return f(0, 0, triangle);
    }
};
