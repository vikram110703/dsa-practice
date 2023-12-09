class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'){
                maxi+=1;
            }
        }
        int curr=maxi;
        for(int i=k;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'){
            curr+=1;
            }
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='o'||s[i-k]=='u'||s[i-k]=='i'){
            curr-=1;
            }
            maxi=max(maxi,curr);
        }
        return maxi;
        
    }
};