class Solution {
public:
    string makeFancyString(string s) {
      string ans;
      int n = s.size();
      for(int i = 0;i<n;i++){
            if(ans.size() >= 2 && s[i] == ans[ans.size()-1] && ans[ans.size()-1] == ans[ans.size()-2]){
                continue;
            }
            else ans += s[i];
      }
      return ans;
    }
};