class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int>sad;
       for(auto it : friendships){
        int u = it[0] - 1;
        int v = it[1] - 1;

        unordered_set<int>langs(languages[u].begin(),languages[u].end());
        bool canTalk = false;

        for(auto it : languages[v]){
            if(langs.count(it)){
                canTalk = true;
                break;
            }
        }
        if(!canTalk){
            sad.insert(u);
            sad.insert(v);
        }
       }

       vector<int>maxlanguages(n+1,0);
        int maxLang = 0;
       for(auto it : sad){
            for(auto lang: languages[it]){
                maxlanguages[lang]++;
                maxLang = max(maxLang,maxlanguages[lang]);

            }
       }

       return sad.size()-maxLang;

    }
};