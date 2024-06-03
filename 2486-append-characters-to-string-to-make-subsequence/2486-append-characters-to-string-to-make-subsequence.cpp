class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size(),m=t.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j==m)break;
            if(s[i]==t[j]){
                j+=1;
            }
        }
        return m-j;
        
    }
};