class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(i>=(n/2))  {           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
cnt2+=1; }
            if(i<n/2){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                    cnt1+=1;
            }
        }
        return (cnt1==cnt2);
    }
};