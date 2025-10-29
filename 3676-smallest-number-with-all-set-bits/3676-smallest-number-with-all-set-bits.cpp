class Solution {
public:
    int smallestNumber(int n) {
        vector<int>arr;
        for(int i = 1;i<=10;i++){
            arr.push_back(pow(2,i));
        }

        int el = *upper_bound(arr.begin(),arr.end(),n);
        return el-1;
    }
};