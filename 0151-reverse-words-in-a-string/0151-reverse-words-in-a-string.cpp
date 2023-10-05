class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            while(i<n&&s[i]==' ')i+=1;
            string ss="";
            while(i<n&&s[i]!=' '){
                ss+=s[i];i+=1;
            }
            if(ss.size())v.push_back(ss);
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(auto &it:v){
            ans+=it;
            ans+=" ";
        }
        ans.erase(ans.size()-1);
        return ans;
            
    }
};