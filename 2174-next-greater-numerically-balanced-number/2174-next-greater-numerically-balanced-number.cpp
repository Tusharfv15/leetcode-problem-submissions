class Solution {
public:
    int digitCount[10] = {0};
    
    int backtrack(int n, int curr, int count) {
        if (count == 0) {
            for (int i = 1; i <= 9; i++) {
                if (digitCount[i] != 0 && digitCount[i] != i)
                    return 0;
            }
            return curr > n ? curr : 0; 
        }

        int result = 0;
        for (int digit = 1; digit <= 9; digit++) {
            if (digitCount[digit] > 0 && digitCount[digit] <= count) {
                digitCount[digit]--;
                result = backtrack(n, curr * 10 + digit, count - 1);
                digitCount[digit]++;
                if (result) return result; 
            }
        }
        return result;
    }
    
    int nextBeautifulNumber(int n) {
        for (int i = 0; i < 10; i++)
            digitCount[i] = i;

        int numDigits = to_string(n).size();
        int result = backtrack(n, 0, numDigits);
        if (result == 0)
            result = backtrack(n, 0, numDigits + 1);

        return result;
    }
};
