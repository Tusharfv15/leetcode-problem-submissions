class Solution {
    int removePairs(string &s,char a,char b,int val){
         stack<char>st;
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(!st.empty()){
                char topCh = st.top();
                if(ch == b&& topCh == a){
                    st.pop();
                    ans+= val;
                    continue;
                }
            }
            st.push(ch);
        }

        string temp;
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s = temp;
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
       
        
        int ans = 0;
        if(x > y){
            ans +=removePairs(s,'a','b',x);
            ans+=removePairs(s,'b','a',y);
        }
        else {
             ans +=removePairs(s,'b','a',y);
            ans+=removePairs(s,'a','b',x);
        }
        return ans;
    }
};