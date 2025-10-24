class Solution {
public:
    bool isBalanced(int start){
        int arr[10] = {0};
        string num = to_string(start);
        for(auto it : num){
            arr[it-'0']++;
        }
        for(int i = 0;i<10;i++){
            if(arr[i] !=0 && arr[i] != i)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        
        int start = n+1;

        while(true){
            if(isBalanced(start))return start;
            else start+=1;
        }
    }
};