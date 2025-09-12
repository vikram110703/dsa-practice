#include<regex>

class Solution {
public:
    static bool cmp(pair<string,string>&a,pair<string,string>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>ans;
        vector<pair<string,string>>letLog;
        vector<string>digLog;
        int n=logs.size();
        
        for(int i=0;i<n;i++){
            int m=logs[i].size();
            bool isLetter=false;
            string idf="";
            int ind=0;
            string logPart="";

            while(logs[i][ind]!=' '){
                idf+=logs[i][ind];
                ind+=1;
            }
            ind+=1;
            logPart=logs[i].substr(ind,m-ind);
            regex pattern("^[0-9]");
            if(regex_search(logPart,pattern)){
               digLog.push_back(logs[i]);
            }
            else{
                letLog.push_back({idf,logPart});
            }
        }

        sort(letLog.begin(),letLog.end(),cmp);
        for(auto &it:letLog){
            ans.push_back(it.first+" "+it.second);
        }
        for(auto &it:digLog){
            ans.push_back(it);
        }

        return ans;
        
    }
};