class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
       
        int  i = 1;
        while(i < n){
            string word1 = words[i-1];
            string word2 = words[i];
            sort(word1.begin(),word1.end());
            sort(word2.begin(),word2.end());

            if(word1 == word2){
                words.erase(words.begin()+i);
                n--;
            }
            else i++;

        }
        return words;
    }
};