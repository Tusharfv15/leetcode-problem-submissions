class Solution {
public:
    int dp[301];
    bool f(int ind,string s,vector<string>&wordDict,set<string>&st){
        if(ind >= s.size() ) return true;
        int len = s.size();

        if(dp[ind] !=-1) return dp[ind];
        for(int i = 1;i<=len;i++){
            string temp = s.substr(ind,i);
            if(st.find(temp) != st.end() && f(ind+i,s,wordDict,st)) return dp[ind] =true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string>st;
        for(auto it: wordDict){
            st.insert(it);
        }
        memset(dp,-1,sizeof(dp));
        return f(0,s,wordDict,st);
    }
};