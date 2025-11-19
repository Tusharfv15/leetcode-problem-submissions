class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
            sort(nums.begin(),nums.end());
            while(true){
                auto el = lower_bound(nums.begin(),nums.end(),original);
                if(el == nums.end())break;
                else if(*el != original)break;
                else if(*el == original)original*=2;
            }
            return original;
    }
};