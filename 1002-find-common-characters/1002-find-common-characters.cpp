class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                freq[i][words[i][j]-'a']+=1;
            }
        }
        map<char,int>mpp;
        for(char i='a';i<='z';i++){
            mpp[i]=120;
        }
        for(int i=0;i<n;i++){
            for(char j='a';j<='z';j++){
                mpp[j]=min(mpp[j],freq[i][j-'a']);
            }
        }
        vector<string>ans;
        for(auto &it:mpp){
            int cnt=it.second;
            if(cnt>=120)continue;
            while(cnt--){
                string tmp="";
                tmp+=it.first;
               ans.push_back(tmp);
            }
        }
        return ans;
        
    }
};