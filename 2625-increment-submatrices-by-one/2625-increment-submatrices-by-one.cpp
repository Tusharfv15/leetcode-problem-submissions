class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (auto it : queries) {

            int startRow = it[0];
            int endRow = it[2];

            int startCol = it[1];
            int endCol = it[3];
            for (int i = startRow; i <= endRow; i++) {
                diff[i][startCol] += 1;
                if (endCol + 1 < n)
                    diff[i][endCol + 1] -= 1;
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                curr += diff[i][j];
                ans[i][j] = curr;
            }
        }
        return ans;
    }
};