class Solution {
public:
    string processStr(string s) {
        string ans;

        for(auto it : s){

            if(it == '*' && ans.size() >=1)ans = ans.substr(0,ans.size()-1);
            if(it == '#' && ans.size()>=1)ans+=ans;
            if(it == '%' && ans.size() >=1){
                reverse(ans.begin(),ans.end());
            }
            else if( (it - 'a') >=0 && (it-'a')<=25)ans+=it;
        }
        return ans;
    }
};