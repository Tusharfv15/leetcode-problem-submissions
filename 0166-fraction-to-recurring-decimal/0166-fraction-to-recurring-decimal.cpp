#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        
        if ((long long)numerator * (long long)denominator < 0) 
            result += '-';

        long long absNum = llabs(numerator);  // ✅ use llabs for long long
        long long absDen = llabs(denominator);

        long long div = absNum / absDen;
        long long rem = absNum % absDen;
        result += to_string(div);
        if (rem == 0) return result;

        result += '.';
        unordered_map<long long, int> mpp; 

        while (rem != 0) {
            if (mpp.count(rem)) {
                result.insert(mpp[rem], "(");
                result += ")";
                break;
            }
            mpp[rem] = result.size();
            rem *= 10;
            div = rem / absDen;
            result += to_string(div);
            rem %= absDen;
        }
        return result;
    }
};
