class Solution {
public:
    
    string chk(string s,int cntt,int n){
        if(cntt==n){
           return s;
        }
        string tmp="";
        int cnt=1;
        int nn=s.size();
        for(int i=0;i<nn;i++){
            char c=s[i];
            cnt=1;
            while(i<nn-1&&s[i]==s[i+1]){
                cnt+=1;i+=1;
            }
                tmp+=(to_string(cnt))+c;
        }
        return chk(tmp,cntt+1,n);
    }
    
    string countAndSay(int n) {
        return chk("1",1,n);
    }
};