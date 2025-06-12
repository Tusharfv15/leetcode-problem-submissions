class Trie {
public:
    struct trieNode {
        bool endOfWord;
        trieNode *children[26];

        trieNode() {
            endOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    trieNode *root;

    Trie() {
        root = new trieNode(); 
    }

    void insert(string word) {
        trieNode *crawl = root;
        for (auto it : word) {
            int ch = it - 'a';
            if (crawl->children[ch] == NULL) {
                crawl->children[ch] = new trieNode();
            }
            crawl = crawl->children[ch];
        }
        crawl->endOfWord = true;
    }

    bool search(string word) {
        trieNode *crawl = root;
        for (auto it : word) {
            int ch = it - 'a';
            if (crawl->children[ch] == NULL) {
                return false;
            }
            crawl = crawl->children[ch];
        }
        return crawl->endOfWord;
    }

    bool startsWith(string prefix) {
        trieNode *crawl = root;
        for (auto it : prefix) {
            int ch = it - 'a';
            if (crawl->children[ch] == NULL) {
                return false;
            }
            crawl = crawl->children[ch];
        }
        return true;
    }
};
