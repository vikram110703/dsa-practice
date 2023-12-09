class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int j=0;
        for(int i=0;i<m;i++){
            if(j<n&&t[i]==s[j])j+=1;
        }
        return j==n;
    }
};