class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        map<char,int>mpp;

      

        int vis[26] = {0};

        for(int i = 0;i<n-1;i++){
            //if(vis[word[i] - 'a'])continue;
            if(word[i] == word[i+1]){
                ans +=1;
            }
        }
        return ans;

    }
};