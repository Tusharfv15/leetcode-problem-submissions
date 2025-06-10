class Solution {
public:
    vector<string> result;
    int r, c;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    struct trieNode {
        bool endOfWord;
        trieNode* children[26];
        string word;
        
        trieNode() {
            endOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    void insert(trieNode* root, string str) {
        trieNode* pCrawl = root;
        for (auto ch : str) {
            if (pCrawl->children[ch - 'a'] == nullptr) {
                pCrawl->children[ch - 'a'] = new trieNode();
            }
            pCrawl = pCrawl->children[ch - 'a'];
        }
        pCrawl->endOfWord = true;
        pCrawl->word = str;
    }

    void DFS(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '$' ||
            root->children[board[i][j] - 'a'] == nullptr) {
            return;
        }
        
        char ch = board[i][j];
        root = root->children[ch - 'a'];
        
        if (root->endOfWord) {
            result.push_back(root->word);
            root->endOfWord = false; // To avoid duplicates
        }
        
        board[i][j] = '$';
        for (auto& p : directions) {
            int new_i = i + p.first;
            int new_j = j + p.second;
            DFS(board, new_i, new_j, root);
        }
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = board.size();
        if (r == 0) return result;
        c = board[0].size();
        
        trieNode* root = new trieNode();
        for (auto& str : words) {
            insert(root, str);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != nullptr) {
                    DFS(board, i, j, root);
                }
            }
        }
        return result;
    }
};