class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        ans = "*";
        int n = num.size();
        bool isChanged = 0;
        for(int i = 0;i<n-2;i++){
            string str;
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                str = num.substr(i,3);
                isChanged = 1;
                if(ans == "*" || str > ans)ans = str;
            }
        }

        if(isChanged)return ans;
        return "";
        
    }
};