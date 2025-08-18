class Solution {
public:
    bool solve(vector<double>&nums){
        if(nums.size() == 1){
            if(abs(nums[0] - 24) < 0.01) return true;
            return false;
        }

        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(i == j)continue;
                double a = nums[i];
                double b = nums[j];

                vector<double>temp;
                for(int k = 0;k<nums.size();k++){
                    if(k == i || k == j)continue;
                    temp.push_back(nums[k]);
                }

                vector<double>possibleVals = {a+b,b-a,a*b,b*a};
                if(abs(b) > 0.0)possibleVals.push_back(a/b);
                if(abs(a) > 0.0)possibleVals.push_back(b/a);

                for(auto it : possibleVals){
                    
                    temp.push_back(it);
                    if(solve(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        
        vector<double>nums;

        for(auto it : cards){
                nums.push_back(1.0*it);
        }

        return solve(nums);
    }
};