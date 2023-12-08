class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        string s="";
        int i=0,j=0;
        while(i<n&&j<m){
            s+=word1[i];
            s+=word2[j];
            i+=1;j+=1;
        }
        while(i<n)s+=word1[i++];
        while(j<m)s+=word2[j++];
        return s;
    }
};