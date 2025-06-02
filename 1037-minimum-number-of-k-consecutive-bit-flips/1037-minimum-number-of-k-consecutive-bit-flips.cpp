class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int>q;
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(!q.empty() && q.front() + k -1 < i)q.pop();
            if((nums[i] + q.size())%2 == 0){
                if(i + k > n)return -1;
                ans +=1;
                q.push(i);
            }
        }

        return ans;
    }
};