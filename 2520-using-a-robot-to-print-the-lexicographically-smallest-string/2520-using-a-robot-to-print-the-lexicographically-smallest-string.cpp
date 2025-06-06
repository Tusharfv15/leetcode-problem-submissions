class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char>suff(n);
        stack<char>st;
        suff[n-1] = s[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i] = min(suff[i+1],s[i]);
        }
        string t;
        for(int i = 0;i<n;i++){

            while(!st.empty() && st.top() <= suff[i]){
                char ch = st.top();
                t+=ch;
                st.pop();
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        return t;

    }
};