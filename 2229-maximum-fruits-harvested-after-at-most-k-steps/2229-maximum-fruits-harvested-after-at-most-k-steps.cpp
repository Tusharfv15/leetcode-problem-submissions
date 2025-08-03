class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int>pos(n);
        vector<int>pref(n,0);
        pref[0] = fruits[0][1];
        for(int i = 0;i<n;i++){
            pos[i] = fruits[i][0];

            if(i > 0 )pref[i] = fruits[i][1] + pref[i-1];
        }
        int ans  = 0;
        for(int d = 0;d<=k/2;d++){
            //Move left first;
            int rem = k - 2*d;
            int i = startPos - d;
            int j = startPos+rem;

            int l = lower_bound(pos.begin(),pos.end(),i) - pos.begin();
            int r = upper_bound(pos.begin(),pos.end(),j) - pos.begin()-1;
          
            if(l <=r){
            int total = pref[r] - (l-1 >=0 ?pref[l-1]:0);
            ans  = max(ans,total);
            }

            // move right first;



             j = startPos+d;
             i = startPos-rem;
            
             l = lower_bound(pos.begin(),pos.end(),i) - pos.begin();
             r = upper_bound(pos.begin(),pos.end(),j) - pos.begin()-1;
           
            if(l <=r){
            int total = pref[r] - (l-1 >=0 ?pref[l-1]:0);
            ans  = max(ans,total);
            }




        }
        return ans;
    }
};