class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string,int>mpp;
        for(int j=0;j<strs.size();j++){
            string s="";
        for(int i=0;i<strs[j].size();i++){
            s+=strs[j][i];
            mpp[s]++;
         }
        }
        string ans="";
        for(auto&it:mpp){
            if(it.second>=strs.size()){
                if(it.first.size()>ans.size()){
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};