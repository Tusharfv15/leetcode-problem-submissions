class Solution {
public:
    long long flowerGame(int n, int m) {
        //case 1
        float num = n/2.0;
        int numOdd = ceil(num);
        int numEven = m/2;
        long long  res1 = 1LL*numOdd*numEven;

        num = m/2.0;
        numOdd = ceil(num);
        numEven = n/2;
        long long res2 = 1LL*numOdd*numEven;

        return res1+res2;


    }
};