class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>ones(n,0);
        if(s[0] == '1')ones[0] = 1;
        int result = 0;
        for(int i = 1;i<n;i++){
            ones[i] = ones[i-1] + (s[i] == '1'? 1 : 0);
        }

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int oneCount = ones[j] - (i-1 >=0 ? ones[i-1]:0);
                int zeroCount = j-i+1-oneCount;

                if(zeroCount*zeroCount > oneCount){
                    int steps = zeroCount*zeroCount - oneCount;
                    j+=steps-1;
                }
                else if(zeroCount*zeroCount > oneCount){
                    result += 1;
                }
                else {
                    result +=1;
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;
                    if(next >= n){
                        result += (n-j-1);
                    }
                    else {
                        result += k;
                    }

                    j = next;

                }
            }
        }
        return result;
    }
};