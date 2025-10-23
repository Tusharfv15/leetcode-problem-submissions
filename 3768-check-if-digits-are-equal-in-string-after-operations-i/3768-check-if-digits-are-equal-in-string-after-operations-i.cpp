class Solution {
public:
    bool hasSameDigits(string s) {
        
        string res = s;
        while(res.size() != 2){
            int n = res.size();
            string temp;
            for(int i = 0;i<n-1;i++){
                char ch = (((res[i]-'0')+(res[i+1]-'0')))%10+'0';
                temp+=ch;
            }
            res = temp;
        }

        if(res[0] == res[1])return true;
        return false;
    }
};