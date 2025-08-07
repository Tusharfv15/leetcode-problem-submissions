class Solution {
public:
    int dp1[1001][1001]; // for f1
    int dp2[1001][1001]; // for f2

    int f1(int i, int j, vector<vector<int>>& fruits, int n) {
        if (i == n - 1 && j == n - 1) return 0;
        if(i == j || i > j ) return 0;
        if (dp1[i][j] != -1) return dp1[i][j];

        int op1 = 0, op2 = 0, op3 = 0;

        if (i + 1 < n && j - 1 >= 0 && i + 1 != j - 1)
            op1 = fruits[i][j] + f1(i + 1, j - 1, fruits, n);

        if (i + 1 < n && i + 1 != j)
            op2 = fruits[i][j] + f1(i + 1, j, fruits, n);

        if (i + 1 < n && j + 1 < n && i + 1 != j + 1)
            op3 = fruits[i][j] + f1(i + 1, j + 1, fruits, n);

        return dp1[i][j] = max({op1, op2, op3});
    }

    int f2(int i, int j, vector<vector<int>>& fruits, int n) {
        if (i == n - 1 && j == n - 1) return 0;
        if(i == j || j >i ) return 0;
        if (dp2[i][j] != -1) return dp2[i][j];

        int op1 = 0, op2 = 0, op3 = 0;

        if (i - 1 >= 0 && j + 1 < n && i - 1 != j + 1)
            op1 = fruits[i][j] + f2(i - 1, j + 1, fruits, n);

        if (j + 1 < n && i != j + 1)
            op2 = fruits[i][j] + f2(i, j + 1, fruits, n);

        if (i + 1 < n && j + 1 < n && i + 1 != j + 1)
            op3 = fruits[i][j] + f2(i + 1, j + 1, fruits, n);

        return dp2[i][j] = max({op1, op2, op3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int c1 = 0;

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        for (int i = 0; i < n; i++) {
            c1 += fruits[i][i]; // main diagonal
        }

        int c2 = f1(0, n - 1, fruits, n);     // top-right to bottom-right
        int c3 = f2(n - 1, 0, fruits, n);     // bottom-left to bottom-right

        return c1 + c2 + c3;
    }
};
