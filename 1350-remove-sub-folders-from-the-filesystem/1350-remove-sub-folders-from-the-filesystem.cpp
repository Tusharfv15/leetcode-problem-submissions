class Solution {
public:
vector<string>ans;
struct trieNode{
    bool endOfWord;
    map<string,trieNode*>children;

    trieNode(){
        endOfWord = false;
  
    }
};
    vector<string>findParts(string word){
        int i = 1;
        vector<string>res;
        int n = word.size();
        while(i < n){
            int j = i;
            while(j < n && word[j] != '/'){
                j++;
            }

            res.push_back(word.substr(i,j-i));
            i = j+1;
        }
        return res;
    }
    void insert(trieNode *root, string word){
            trieNode* crawl = root;
             vector<string>parts = findParts(word);

             for(auto it : parts){
                if(crawl->endOfWord == true) return;
                if(crawl->children.find(it) == crawl->children.end()){
                    crawl->children[it] = new trieNode();

                }
                crawl = crawl->children[it];
             }
             crawl->endOfWord = true;
             ans.push_back(word);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
            trieNode *root = new trieNode();
            sort(folder.begin(),folder.end());
            for(auto it : folder){
                insert(root,it);
            }
            return ans;
    }
};