class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>storeVersion1;
        vector<int>storeVersion2;

        int i = 0;
        string s;
        while(i < version1.size()){
            if(version1[i] == '.'){
                storeVersion1.push_back(stoi(s));
                s="";
            }
            else {
                s+=version1[i];
            }
            i++;
        }
        if(!s.empty())storeVersion1.push_back(stoi(s));
         i = 0;
        s="";
        while(i < version2.size()){
            if(version2[i] == '.'){
                storeVersion2.push_back(stoi(s));
                s="";
            }
            else {
                s+=version2[i];
            }
            i++;
        }
        if(!s.empty())storeVersion2.push_back(stoi(s));

        if (storeVersion2.size() > storeVersion1.size()) {
        storeVersion1.resize(storeVersion2.size(), 0);
        }        
        if (storeVersion1.size() > storeVersion2.size()) {
        storeVersion2.resize(storeVersion1.size(), 0);
        }

        int n = storeVersion1.size();

        for(int i = 0;i<n;i++){
            if(storeVersion1[i] > storeVersion2[i]) return 1;
            else if(storeVersion2[i] > storeVersion1[i]) return -1;
        }
        return 0;        
    }
};