class Solution {
public:
    string mergeAlternately(string s, string ss) {
        int n=s.size(),m=ss.size(),i=0,j=0;
        string ans="";
        while(i<n&&j<m)
        {
            ans+=s[i++];
            ans+=ss[j++];
        }
        while(i<n)ans+=s[i++];
        while(j<m)ans+=ss[j++];
        return ans;
        
        
    }
};