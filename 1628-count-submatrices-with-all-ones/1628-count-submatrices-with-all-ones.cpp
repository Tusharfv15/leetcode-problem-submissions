class Solution {
public:
    vector<int> findNse(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if(st.empty()) 
                nse[i] = n;
            else 
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    
    vector<int> findPse(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if(st.empty()) 
                pse[i] = -1;
            else 
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> heights(m, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // For each column, count submatrices ending at row i
            for(int k = 0; k < m; k++) {
                if(heights[k] == 0) continue;
                
                int minHeight = heights[k];
                
                // Count submatrices with right boundary at column k
                for(int j = k; j >= 0; j--) {
                    minHeight = min(minHeight, heights[j]);
                    if(minHeight == 0) break;
                    
                    // Add all submatrices with width (k-j+1) and heights 1 to minHeight
                    ans += minHeight;
                }
            }
        }
        
        return ans;
    }
};