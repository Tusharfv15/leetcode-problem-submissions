class Solution {
public:
    bool check(int a, int b){
        while(a){
            int m = a%10;
            a = a/10;
            if(m == 0) return true;
        }
        while(b){
            int m = b%10;
            b = b/10;
            if(m == 0) return true;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-1;
        while(check(a,b)){
            a = a+1;
            b = b-1;
            
        }

        return {a,b};
    }
};