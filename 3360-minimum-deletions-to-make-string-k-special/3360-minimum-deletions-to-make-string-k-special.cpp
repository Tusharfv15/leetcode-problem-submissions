class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();

        vector<int>freq(26,0);
        for(int i = 0;i<n;i++){
            freq[word[i] - 'a']++;
        }
        int ans = INT_MAX;
        for(int i = 0;i<26;i++){
            int freq_i = freq[i];
            int del = 0;
            for(int j = 0;j<26;j++){
                if(i == j)continue;
                
                if(freq[i] > freq[j])del+=freq[j];
                else if(abs(freq[j] - freq[i]) >=k)del+= abs(freq[j] - freq[i] -k);
            }
            ans = min(ans,del);
        }
        return ans;
    }
};