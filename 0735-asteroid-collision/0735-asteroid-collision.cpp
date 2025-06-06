class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            if(asteroids[i] < 0){
                bool broken = 0;
                while(!st.empty() && st.top() <= abs(asteroids[i])){
                    if(st.top() == abs(asteroids[i])){
                    st.pop();
                    broken = 1;
                    break;
                    }
                    st.pop();
                }
                if(!broken && st.empty())ans.push_back(asteroids[i]);
            }
        }
        vector<int>storePos;
        while(!st.empty()){
            int el = st.top();
            st.pop();
            storePos.push_back(el);
        }
        reverse(storePos.begin(),storePos.end());

        for(auto it : storePos)ans.push_back(it);
        return ans;
        

        
    }
};