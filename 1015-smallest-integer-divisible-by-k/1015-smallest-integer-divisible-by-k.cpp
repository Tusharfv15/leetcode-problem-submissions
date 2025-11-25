class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0)return -1;
        int curr = 1%k;
        int cnt = 1;
        while(true){
            if(cnt > k)return -1;
            if(curr == 0)return cnt;
            curr = (curr*10 + 1)%k;
            cnt++;
        }
        return -1;
    }
};