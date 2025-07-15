class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        int vowCount = 0;
        int consCount = 0;

        for(char it : word) {
            if(!isalnum(it)) return false;

            char lower = tolower(it); 
            if(isalpha(it)) {
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    vowCount++;
                } else {
                    consCount++;
                }
            }
        }

        return vowCount > 0 && consCount > 0;
    }
};
