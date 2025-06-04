/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    int getImportance(vector<Employee*> employees, int id) {
        int n = 0;
        for(auto it : employees){
                n = max(n,it->id);
        }
        //return n;
        vector<vector<int>>adjList(n+1);

        for(auto it : employees){
            for(auto neighbours:it->subordinates){
                adjList[it->id].push_back(neighbours);
            }
        }
        vector<int>StoreImportance(n+1,0);
        for(auto it : employees){
            StoreImportance[it->id] = it->importance;
        }

        
        int ans = 0;
        queue<int>q;
        q.push(id);
        //vector<int>vis(n+1,0);

        while(!q.empty()){
            int node = q.front();
            ans += StoreImportance[node];
            q.pop();
            for(auto it : adjList[node]){
                q.push(it);
            }
        }
        return ans;
    }
};