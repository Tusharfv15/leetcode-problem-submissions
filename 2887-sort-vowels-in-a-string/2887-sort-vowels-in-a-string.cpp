class Solution {
public:
    string sortVowels(string s) {
        string storeAscii;

        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'){
                storeAscii+=s[i];
                s[i] = '*';
            }
        }

        sort(storeAscii.begin(),storeAscii.end());
        int i = 0;
        for(int j = 0;j<s.size();j++){
            if(s[j] == '*'){
                s[j] = storeAscii[i];
                i++;
            }
        }
        return s;
    }
};