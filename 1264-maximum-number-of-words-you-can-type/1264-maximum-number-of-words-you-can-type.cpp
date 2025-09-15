class Solution {
public:
    bool check(string &str, unordered_set<char>st){
        
        for(auto it : str){
            if(st.count(it))return false;
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int i = 0;
        unordered_set<char>st;
        for(auto it : brokenLetters){
            st.insert(it);
        }
        int ans = 0;
        string str;
        while(i < n){
            if(text[i] == ' '){
                if(check(str,st))ans++;
                str="";
            }
            else {
                str+=text[i];
            }
            i++;
        }

        if(check(str,st))ans++;
        return ans;
    }
};