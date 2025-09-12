class Solution {
public:
    bool doesAliceWin(string s) {
        int countVow = 0;

        for(auto it : s){
            if(it == 'a' || it == 'e' ||it == 'i' ||it == 'o' ||it == 'u'){
                countVow++;
            }
        }

        if(countVow)return true;
        return false;


    }
};