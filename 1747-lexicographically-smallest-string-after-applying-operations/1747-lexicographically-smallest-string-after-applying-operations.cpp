class Solution {
public:
    string rotate(string &curr,int b){
        reverse(curr.begin(),curr.end());
        reverse(curr.begin(),curr.begin()+b);
        reverse(curr.begin()+b,curr.end());

        return curr;
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string>q;
        unordered_set<string>vis;
        q.push(s);
        vis.insert(s);
        string ans;
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(ans.size() == 0 || curr < ans){
                ans = curr;
            }

            string temp = curr;
            for(int i = 1;i<n;i+=2){
                temp[i] = (((temp[i]-'0')+a)%10)+'0';

            }
            if(vis.count(temp) == 0){
                q.push(temp);
                vis.insert(temp);
            }
            string rotated = rotate(curr,b);
            if(vis.count(rotated) == 0){
                q.push(rotated);
                vis.insert(rotated);
            }

        }
        return ans;

    }
};