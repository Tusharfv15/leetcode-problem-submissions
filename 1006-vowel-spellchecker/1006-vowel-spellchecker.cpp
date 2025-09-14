class Solution {
public:
    string findLower(string s) {
        string ans;
        for (auto it : s) {
            ans += tolower(it);
        }
        return ans;
    }

    string findVow(string s) {

        string ans;
        for (auto it : s) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                ans += '*';
            else
                ans += it;
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        int n = wordlist.size();
        int m = queries.size();

        unordered_set<string> st;
        unordered_map<string, string> caseMpp;

        unordered_map<string, string> VowMpp;

        for (auto it : wordlist) {
            st.insert(it);

            string lower = findLower(it);
            if (caseMpp.find(lower) == caseMpp.end()) {
                caseMpp[lower] = it;
            }

            string vow = findVow(lower);
            if (VowMpp.find(vow) == VowMpp.end()) {
                VowMpp[vow] = it;
            }
        }
        vector<string>ans;
        for (auto it : queries) {
            if (st.count(it)) {
                ans.push_back(it);
                continue;
            }

            string lower = findLower(it);
            if (caseMpp.find(lower) != caseMpp.end()) {
                ans.push_back(caseMpp[lower]);
                continue;
            }

            string vow = findVow(lower);
            if (VowMpp.find(vow) != VowMpp.end()) {
                ans.push_back(VowMpp[vow]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};