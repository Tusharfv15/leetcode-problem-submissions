class Solution {
public:
    long long sum = 0;
    set<pair<int,int>>main;
    set<pair<int,int>>sec;

    void insertInSet(const pair<int,int>&p,int x){
        if(main.size() < x || p > *main.begin()){
            sum += 1LL*p.first*p.second;
            main.insert(p);


            if(main.size() > x){
                auto smallest = *main.begin();
                sum-=1LL*smallest.first*smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        }
        else {
            sec.insert(p);
        }
    }

    void removeFromSet(const pair<int,int>&p,int x){
        if(main.find(p) != main.end()){
            sum-=1ll*p.first*p.second;
            main.erase(p);

            if(!sec.empty()){
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += 1LL*largest.first*largest.second;
            }
        }
        else {
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long>result;

        unordered_map<int,int>mpp;
        int i = 0;
        int j = 0;

        while( j < n){
            if(mpp[nums[j]] > 0){
                removeFromSet({mpp[nums[j]],nums[j]},x);
            }
            mpp[nums[j]]++;
            insertInSet({mpp[nums[j]],nums[j]},x);

            if(j - i + 1 == k){
                result.push_back(sum);
                removeFromSet({mpp[nums[i]],nums[i]},x);
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0)mpp.erase(nums[i]);
                else insertInSet({mpp[nums[i]],nums[i]},x);
                i++;
            }
            j++;
        }
        return result;

    }
};