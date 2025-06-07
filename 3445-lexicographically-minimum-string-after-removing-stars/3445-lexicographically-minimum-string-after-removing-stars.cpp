  class cmp {
public:
	bool operator()(const pair<char,int> a, const pair<char,int> b) {
		if(a.first > b.first) {
			return true;
		}
		else if(a.first == b.first){
            return a.second < b.second;
        }
        else return false;
	}
};
class Solution {
  
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;
        
        for(int i = 0;i<n;i++){
            if(s[i] != '*')pq.push({s[i],i});
            else {
                if(!pq.empty())pq.pop();
            }
        }
       
       vector<pair<int,char>>storeString;

       while(!pq.empty()){
        char el = pq.top().first;
        int ind = pq.top().second;
        pq.pop();
        storeString.push_back({ind,el});
       }
       sort(storeString.begin(),storeString.end());
       string ans;
       for(auto it : storeString)ans+=it.second;
       return ans;
        
    }
};