class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int strt=0,end=n-1;
        while(end>strt){
            if(s[strt]!=s[end])break;
            char a=s[strt];
           int i=strt;
            while(i<n&&s[i]==a)i+=1;
            strt=i;
            i=end;
            while(i>=0&&s[i]==a)i-=1;
            end=i;
        }
        if(end<strt)return 0;
        return end-strt+1;
    }
};