class Solution {
public:
    int minMaxDifference(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);

        int n = num1.size();
        char to_convert_1;
        for(int i = 0;i<n;i++){
            if(num1[i] < '9'){
                    to_convert_1 = num1[i];
                    break;
            }
        }
        char to_convert_2;
         for(int i = 0;i<n;i++){
            if(num1[i] > '0'){
                    to_convert_2 = num1[i];
                    break;
            }
        }

        for(int i = 0;i<n;i++){
            if(num1[i] == to_convert_1)num1[i] = '9';
            if(num2[i] == to_convert_2)num2[i] = '0';
        }
        int nums1 = stoi(num1);
        int nums2 = stoi(num2);
        return nums1 - nums2;

    }
};